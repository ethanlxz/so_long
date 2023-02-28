/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:05:06 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:24:28 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Checks if the map is a rectangular

static int	check_length(t_game *game)
{
	int	len;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		len = ft_strlen(game->map[y]);
		if (len != game->map_length)
			return (0);
	}
	return (1);
}

// Checks if the map is surrounded by walls

static int	check_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[0][x] != 0
	&& game->map[game->map_height - 1][x] != 0)
	{
		if (game->map[0][x] != '1' ||
		game->map[game->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (game->map[y] != 0)
	{
		if (game->map[y][0] != '1' ||
		game->map[y][game->map_length - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

// Counts the total 'C' and ensure 'P' and 'E' is not more than 1 or less than 0

static int	count_pec(t_game *game)
{
	int	x;
	int	y;
	int	p;
	int	e;

	p = 0;
	e = 0;
	game->total_c = 0;
	x = -1;
	while (game->map[++x] != 0)
	{
		y = -1;
		while (game->map[x][++y] != 0)
		{
			if (game->map[x][y] == 'P')
				p++;
			else if (game->map[x][y] == 'E')
				e++;
			else if (game->map[x][y] == 'C')
				game->total_c++;
		}
	}
	if (p != 1 || game->total_c == 0 || e != 1)
		return (0);
	return (1);
}

// Checks the map for any char other than "PEC01"
// and checks amount of 'N' for enemy
// 'N' must be not more than 1

static int	check_format(char **map)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	n = 0;
	while (map[x] != 0)
	{
		y = 0;
		while (map[x][y] != 0)
		{
			if (map[x][y] != 'P' && map[x][y] != 'E' && map[x][y] != 'C'
			&& map[x][y] != '0' && map[x][y] != '1' && map[x][y] != 'N')
				return (0);
			if (map[x][y] == 'N')
				n++;
			y++;
		}
		x++;
	}
	if (n > 1)
		return (0);
	else
		return (1);
}

int	check_map(t_game *game)
{
	if (!check_newline(game))
		return (0);
	if (!check_length(game))
		return (0);
	if (!check_wall(game))
		return (0);
	if (!count_pec(game))
		return (0);
	if (!check_format(game->map))
		return (0);
	if (!path_checker(game))
		return (0);
	return (1);
}

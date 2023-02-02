/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:05:06 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/02 17:34:27 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Checks if the map is a rectangular

static int	check_length(t_game_map *game_map)
{
	int	len;
	int	row;

	while (row <= game_map->map_height)
	{
		len = ft_strlen(game_map->map[row]);
		if (len != game_map->map_length)
			return (0);
		row++;
		len = 0;
	}
	return (1);
}

// Checks if the map is surrounded by walls

static int	check_wall(t_game_map *game_map)
{
	int	x;
	int	y;

	y = 0;
	while (game_map->map[0][y] != '\0'
	&& game_map->map[game_map->map_length - 1][y] != '\0')
	{
		if (game_map->map[0][y] != '1' ||
		game_map->map[game_map->map_length - 1][y] != '1')
			return (0);
		y++;
	}
	x = 1;
	while (game_map->map[x] != '\0')
	{
		if (game_map->map[x][0] != '1' ||
		game_map->map[x][game_map->map_height - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

// Counts the total 'C' and ensure 'P' and 'E' is not more than 1 or less than 0

static int	count_pec(t_game_map *game_map)
{
	int	x;
	int	y;
	int	p;
	int	e;

	p = 0;
	e = 0;
	game_map->total_c = 0;
	x = -1;
	while (game_map->map[++x] != '\0')
	{
		y = -1;
		while (game_map->map[x][++y] != '\0')
		{
			if (game_map->map[x][y] == 'P')
				p++;
			else if (game_map->map[x][y] == 'E')
				e++;
			else if (game_map->map[x][y] == 'C')
				game_map->total_c++;
		}
	}
	if (p != 1 || game_map->total_c == 0 || e == 0)
		return (0);
	return (1);
}

// Checks the map for any char other than "PEC01"

static int	check_format(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != '\0')
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] != 'P' && map[x][y] != 'E' && map != 'C'
			&& map[x][y] != '0' && map[x][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_map(t_game_map *game_map)
{
	
}
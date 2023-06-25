/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:45:38 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 16:03:52 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// free the map double array 

void	free_map(char **map_data, int size)
{
	int	count;

	count = 0;
	while (count <= size)
	{
		free(map_data[count]);
		count++;
	}
	free(map_data);
	map_data = NULL;
}

// Finds the player x and y to find the starting point of the game

int	player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != 0)
	{
		x = 0;
		while (game->map[y][x] != 0)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Duplicates the map from the game_map struct

char	**map_dup(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (game->map_height + 1));
	if (map == NULL)
		return (NULL);
	map[game->map_height] = 0;
	while (i < game->map_height)
	{
		map[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (map);
}

// After floodfill , 'E' 'C' will be replaced with 'F'
// If 'E' is not found means there's a valid path from starting point
// If not , then there's no path from starting point to 'E'

int	check_ce(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// Checks if there's a valid path in a game to the exit

int	path_checker(t_game *game)
{
	char	**map;
	t_point	size;
	t_point	begin;

	map = NULL;
	player_pos(game);
	map = map_dup(game);
	size.x = game->map_length;
	size.y = game->map_height;
	begin.x = game->player_x;
	begin.y = game->player_y;
	flood_fill(map, size, begin);
	if (!check_ce(map))
	{
		free_map(map, game->map_height);
		return (0);
	}
	free_map(map, game->map_height);
	return (1);
}

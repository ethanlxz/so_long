/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:04:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/22 17:11:30 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// init the default img for all sprites

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "assets/0.xpm", &game->img_l, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/1.xpm", &game->img_l, &game->img_h);
	game->img_p = mlx_xpm_file_to_image
		(game->mlx, "assets/PR.xpm", &game->img_l, &game->img_h);
	game->img_c = mlx_xpm_file_to_image
		(game->mlx, "assets/C.xpm", &game->img_l, &game->img_h);
	game->img_e = mlx_xpm_file_to_image
		(game->mlx, "assets/E.xpm", &game->img_l, &game->img_h);
	game->img_n = mlx_xpm_file_to_image
		(game->mlx, "assets/NR.xpm", &game->img_l, &game->img_h);
}

// create length and height of the window

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_length = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_height = i * 64 + 64;
}

// gets the enemy position

void	get_enemy_pos(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y] != 0)
	{
		x = -1;
		while (game->map[y][++x] != 0)
		{
			if (game->map[y][x] == 'E')
			{
				game->enemy_x = x;
				game->enemy_y = y;
			}
		}
	}
}

// game initiation

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window
		(game->mlx, game->map_length, game->map_height, "so_long");
	game->moves = 0;
	img_init(game);
	get_enemy_pos(game);
	map_draw(game);
}

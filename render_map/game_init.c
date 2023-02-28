/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:04:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:19:09 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// init the default img for all sprites

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "textures/0.xpm", &game->img_l, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "textures/1.xpm", &game->img_l, &game->img_h);
	game->img_p = mlx_xpm_file_to_image
		(game->mlx, "textures/PR.xpm", &game->img_l, &game->img_h);
	game->img_c = mlx_xpm_file_to_image
		(game->mlx, "textures/C.xpm", &game->img_l, &game->img_h);
	game->img_e = mlx_xpm_file_to_image
		(game->mlx, "textures/E.xpm", &game->img_l, &game->img_h);
	game->img_n = mlx_xpm_file_to_image
		(game->mlx, "textures/NR.xpm", &game->img_l, &game->img_h);
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

// game initiation

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window
		(game->mlx, game->map_length, game->map_height, "so_long");
	game->moves = 0;
	game->c_anim = 1;
	img_init(game);
	map_draw(game);
}

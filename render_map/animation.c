/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:40:13 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/27 21:50:54 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// too many if statments lol

static void	animation2(t_game *game)
{
	if (game->c_anim == 5)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C5.xpm", &game->img_l, &game->img_h);
	else if (game->c_anim == 6)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C6.xpm", &game->img_l, &game->img_h);
	else if (game->c_anim == 7)
	{
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C1.xpm", &game->img_l, &game->img_h);
		game->c_anim = 0;
	}
}

// animation for collectibles

int	animation(t_game *game)
{
	long	loop;

	loop = 0;
	while (loop <= 30000000)
	{
		loop++;
	}
	loop = 0;
	if (game->c_anim == 1)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C1.xpm", &game->img_l, &game->img_h);
	else if (game->c_anim == 2)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C2.xpm", &game->img_l, &game->img_h);
	else if (game->c_anim == 3)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C3.xpm", &game->img_l, &game->img_h);
	else if (game->c_anim == 4)
		game->img_c = mlx_xpm_file_to_image(game->mlx,
				"textures/coin/C4.xpm", &game->img_l, &game->img_h);
	animation2(game);
	game->c_anim++;
	map_draw(game);
	return (0);
}

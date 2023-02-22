/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:15:11 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/22 17:46:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rip_draw(t_game *game)
{
	int	rip_anim;

	rip_anim = 0;
	mlx_destroy_image(game->mlx, game->img_p);
	if (rip_anim == 1)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/1.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 2)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/2.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 3)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/3.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 4)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/4.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 5)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/4.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 6)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/4.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 7)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/4.xpm", &game->img_l, &game->img_h);
	else if (rip_anim == 8)
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "../assets/rip/4.xpm", &game->img_l, &game->img_h);
	map_draw(game);
	rip_anim++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:15:11 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/26 20:15:45 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	rip_draw(t_game *game)
{
	int	loop;

	loop = 0;
	while (loop <= 1000)
	{
		loop++;
	}
	loop = 0;
	// mlx_destroy_image(game->mlx, game->img_p);
	if (game->rip_anim == 1)
		game->img_p = mlx_xpm_file_to_image(game->mlx,
				"assets/rip/R1.xpm", &game->img_l, &game->img_h);
	else if (game->rip_anim == 2)
		game->img_p = mlx_xpm_file_to_image(game->mlx,
				"assets/rip/R2.xpm", &game->img_l, &game->img_h);
	else if (game->rip_anim == 3)
		game->img_p = mlx_xpm_file_to_image(game->mlx,
				"assets/rip/R3.xpm", &game->img_l, &game->img_h);
	else if (game->rip_anim == 4)
		game->img_p = mlx_xpm_file_to_image(game->mlx,
				"assets/rip/R4.xpm", &game->img_l, &game->img_h);
	printf("player: %p\n", game->img_p);
	map_draw(game);
	game->rip_anim++;
}

void	rip(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("test %i", i);
		rip_draw(game);
		i++;
	}
	ft_printf("\033[0;31mYou lost ! D:\n\033[0m");
	exit_game(game);
}

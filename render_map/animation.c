/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:40:13 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 16:58:37 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// animation for collectibles

int	animation(t_game *game)
{
	long		loop;
	static char	*strlist_img[] = {
		"textures/coin/C1.xpm",
		"textures/coin/C2.xpm",
		"textures/coin/C3.xpm",
		"textures/coin/C4.xpm",
		"textures/coin/C5.xpm",
		"textures/coin/C6.xpm"
	};

	loop = 0;
	while (loop <= 30000000)
	{
		loop++;
	}
	game->img_c = mlx_xpm_file_to_image(game->mlx,
			strlist_img[game->c_anim++], &game->img_l, &game->img_h);
	game->c_anim %= 6;
	map_draw(game);
	return (0);
}

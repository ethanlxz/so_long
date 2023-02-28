/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:26:10 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 16:20:42 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// draw img

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 64, y * 64 + 64);
}

// sets the player pos and then img_draw

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	img_draw(game, image, x, y);
}

// sets the enemy pos and then img_draw

static void	enemy_draw(t_game *game, void *image, int x, int y)
{
	game->enemy_x = x;
	game->enemy_y = y;
	img_draw(game, image, x, y);
}

// loops through the double array and renders the img

int	map_draw(t_game	*game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->img_p, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_c, x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_e, x, y);
			else if (game->map[y][x] == 'N')
				enemy_draw(game, game->img_n, x, y);
		}
	}
	return (0);
}

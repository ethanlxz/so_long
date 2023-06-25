/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:41:29 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:40:11 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// changes the image of 'N' whenever arrow keys is pressed

static void	enemy_update_image(char key, t_game *game)
{
	if (key == 'w')
		game->img_n = mlx_xpm_file_to_image
			(game->mlx, "textures/NR.xpm", &game->img_l, &game->img_h);
	else if (key == 's')
		game->img_n = mlx_xpm_file_to_image
			(game->mlx, "textures/NL.xpm", &game->img_l, &game->img_h);
	else if (key == 'd')
		game->img_n = mlx_xpm_file_to_image
			(game->mlx, "textures/NR.xpm", &game->img_l, &game->img_h);
	else if (key == 'a')
		game->img_n = mlx_xpm_file_to_image
			(game->mlx, "textures/NL.xpm", &game->img_l, &game->img_h);
}

void	enemy_move(t_game *game, t_point move, char key)
{
	const t_point	to = (t_point)
	{.x = game->enemy_x + move.x, .y = game->enemy_y + move.y};
	const char		tileto = game->map[to.y][to.x];

	enemy_update_image(key, game);
	if (tileto == 'P')
		lose_game(game);
	else if (tileto == '1' || tileto == 'C' || tileto == 'E')
		return ;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[to.y][to.x] = 'N';
		game->map[game->enemy_y][game->enemy_x] = '0';
		map_draw(game);
	}
}

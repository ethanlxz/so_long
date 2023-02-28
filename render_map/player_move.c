/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:46:51 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:28:13 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// changes the image of 'P' whenever "WASD" is pressed 

static void	player_update_image(char key, t_game *game)
{
	if (key == 'w')
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "textures/PR.xpm", &game->img_l, &game->img_h);
	else if (key == 's')
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "textures/PL.xpm", &game->img_l, &game->img_h);
	else if (key == 'd')
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "textures/PR.xpm", &game->img_l, &game->img_h);
	else if (key == 'a')
		game->img_p = mlx_xpm_file_to_image
			(game->mlx, "textures/PL.xpm", &game->img_l, &game->img_h);
}

// if player collected all the 'C' and went to 'E'

static void	win_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_printf("\033[0;32mYou won! :D\n\033[0m");
	exit_game(game);
}

// player move conditions

void	player_move(t_game *game, t_point move, char key)
{
	const t_point	to = (t_point)
	{.x = game->player_x + move.x, .y = game->player_y + move.y};
	const char		tileto = game->map[to.y][to.x];

	player_update_image(key, game);
	if (tileto == 'E' && game->total_c == 0)
		win_game(game);
	else if (tileto == 'N')
		lose_game(game);
	else if (tileto == '1' || tileto == 'E')
		return ;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (tileto == 'C')
			game->total_c -= 1;
		game->map[to.y][to.x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->moves++;
		map_draw(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:50:43 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/17 16:03:13 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->player_y -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->player_y += 1;
		player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->player_x += 1;
		player_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->player_x -= 1;
		player_a(game);
	}
}

static void	player_key(int keycode, t_game *game)
{
	if (keycode == KEY_UP)
	{
		game->player_y -= 1;
		player_w(game);
	}
	else if (keycode == KEY_DOWN)
	{
		game->player_y += 1;
		player_s(game);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player_x += 1;
		player_d(game);
	}
	else if (keycode == KEY_LEFT)
	{
		game->player_x -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		player_key(keycode, game);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		enemy_key(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	//mlx_loop_hook(game->mlx, animation, game);
}

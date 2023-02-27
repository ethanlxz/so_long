/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:50:43 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/27 21:36:33 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// when "WASD" keys are pressed, what will happen to the player x and y

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

// when arrow keys are pressed, what will happen to the player x and y

static void	enemy_key(int keycode, t_game *game)
{
	if (keycode == KEY_UP)
	{
		game->enemy_y -= 1;
		enemy_w(game);
	}
	else if (keycode == KEY_DOWN)
	{
		game->enemy_y += 1;
		enemy_s(game);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->enemy_x += 1;
		enemy_d(game);
	}
	else if (keycode == KEY_LEFT)
	{
		game->enemy_x -= 1;
		enemy_a(game);
	}
}

// Conditions if various keys are pressed

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		player_key(keycode, game);
		display_title(game);
		display_moves('P', game);
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		enemy_key(keycode, game);
		display_title(game);
		display_moves('E', game);
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_loop_hook(game->mlx, animation, game);
}

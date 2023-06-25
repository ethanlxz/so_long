/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:50:43 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:38:25 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// {.x = 0, .y = -1} W
// {.x = -1, .y = 0} A
// {.x = 0, .y = 1} S
// {.x = 1, .y = 0} D

// when "WASD" keys are pressed, what will happen to the player x and y

static void	player_key(int keycode, t_game *game)
{
	t_point	move;

	move = (t_point){.x = 0, .y = 0};
	if (keycode == KEY_W)
	{
		move.y -= 1;
		player_move(game, move, 'w');
	}
	else if (keycode == KEY_S)
	{
		move.y += 1;
		player_move(game, move, 's');
	}
	else if (keycode == KEY_D)
	{
		move.x += 1;
		player_move(game, move, 'd');
	}
	else if (keycode == KEY_A)
	{
		move.x -= 1;
		player_move(game, move, 'a');
	}
}

// when arrow keys are pressed, what will happen to the player x and y

static void	enemy_key(int keycode, t_game *game)
{
	t_point	move;

	move = (t_point){.x = 0, .y = 0};
	if (keycode == KEY_UP)
	{
		move.y -= 1;
		enemy_move(game, move, 'w');
	}
	else if (keycode == KEY_DOWN)
	{
		move.y += 1;
		enemy_move(game, move, 's');
	}
	else if (keycode == KEY_RIGHT)
	{
		move.x += 1;
		enemy_move(game, move, 'd');
	}
	else if (keycode == KEY_LEFT)
	{
		move.x -= 1;
		enemy_move(game, move, 'a');
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

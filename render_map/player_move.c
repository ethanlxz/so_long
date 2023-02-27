/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:46:51 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/27 21:47:08 by etlaw            ###   ########.fr       */
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

// First "IF" checks whether player is going to exit 
// and has collected all collectables.

// Second "ELSE IF" checks whether player is going to enemy position
// and will explode and become a tombstone.

// Third "ELSE IF" checks whether player is going into a wall
// or exit which can't be exited due to uncollected collectibles.

// "ELSE" just let the player roam around the map
// and collect collectibles.

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->total_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		ft_printf("\033[0;32mYou won! :D\n\033[0m");
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'N')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->total_c -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->total_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		ft_printf("\033[0;32mYou won! :D\n\033[0m");
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'N')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->total_c -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->total_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		ft_printf("\033[0;32mYou won! :D\n\033[0m");
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'N')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->total_c -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->player_y][game->player_x] == 'E' && game->total_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		ft_printf("\033[0;32mYou won! :D\n\033[0m");
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'N')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->total_c -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

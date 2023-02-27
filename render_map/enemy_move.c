/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:41:29 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/27 21:47:22 by etlaw            ###   ########.fr       */
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

// First "IF" enemy touches the player then player dies

// Second "IF" enemy touches collectibles, walls and exit,
// enemy remains in the same position

// "ELSE" lets the enemy roam around the map

void	enemy_w(t_game *game)
{
	enemy_update_image('w', game);
	if (game->map[game->enemy_y][game->enemy_x] == 'P')
	{
		ft_printf("\033[0;31mYou lost ! D:\n\033[0m");
		lose_game(game);
	}
	else if (game->map[game->enemy_y][game->enemy_x] == '1'
			|| game->map[game->enemy_y][game->enemy_x] == 'C'
			|| game->map[game->enemy_y][game->enemy_x] == 'E')
		game->enemy_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->enemy_y][game->enemy_x] = 'N';
		game->map[game->enemy_y + 1][game->enemy_x] = '0';
		map_draw(game);
	}
}

void	enemy_a(t_game *game)
{
	enemy_update_image('a', game);
	if (game->map[game->enemy_y][game->enemy_x] == 'P')
		lose_game(game);
	else if (game->map[game->enemy_y][game->enemy_x] == '1'
			|| game->map[game->enemy_y][game->enemy_x] == 'C'
			|| game->map[game->enemy_y][game->enemy_x] == 'E')
		game->enemy_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->enemy_y][game->enemy_x] = 'N';
		game->map[game->enemy_y][game->enemy_x + 1] = '0';
		map_draw(game);
	}
}

void	enemy_s(t_game *game)
{
	enemy_update_image('s', game);
	if (game->map[game->enemy_y][game->enemy_x] == 'P')
		lose_game(game);
	else if (game->map[game->enemy_y][game->enemy_x] == '1'
			|| game->map[game->enemy_y][game->enemy_x] == 'C'
			|| game->map[game->enemy_y][game->enemy_x] == 'E')
		game->enemy_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->enemy_y][game->enemy_x] = 'N';
		game->map[game->enemy_y - 1][game->enemy_x] = '0';
		map_draw(game);
	}
}

void	enemy_d(t_game *game)
{
	enemy_update_image('d', game);
	if (game->map[game->enemy_y][game->enemy_x] == 'P')
		lose_game(game);
	else if (game->map[game->enemy_y][game->enemy_x] == '1'
			|| game->map[game->enemy_y][game->enemy_x] == 'C'
			|| game->map[game->enemy_y][game->enemy_x] == 'E')
		game->enemy_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->enemy_y][game->enemy_x] = 'N';
		game->map[game->enemy_y][game->enemy_x - 1] = '0';
		map_draw(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:04:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/10 16:11:25 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/0.xpm", &game->img_l, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/1.xpm", &game->img_l, &game->img_h);
	game->img_p = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/P.xpm", &game->img_l, &game->img_h);
	game->img_c = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/C.xpm", &game->img_l, &game->img_h);
	game->img_e = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/E.xpm", &game->img_l, &game->img_h);
	game->img_n = mlx_xpm_file_to_image
		(game->mlx, "../assets/images/N.xpm", &game->img_l, &game->img_h);
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_length = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_height = i * 32 + 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window
		(game->mlx, game->map_length, game->map_height, "so_long");
	game->moves = 0;
	img_init(game);
}

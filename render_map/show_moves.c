/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:28:47 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/27 19:05:05 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// prints out the moves in terminal
// and in the game window

void	display_moves(char who, t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	if (who == 'P')
		ft_printf("\033[0;31mMOVES : %s\n\033[0m", str);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 100, 20, 0xFFFFFF, str);
	free(str);
}

// prints "so_long by etlaw :)"

void	display_title(t_game *game)
{
	mlx_string_put(game->mlx, game->win, (game->map_length / 2), 20,
		0xFFFFFF, "so_long by etlaw :)");
}

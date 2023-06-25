/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:30:22 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/25 21:07:31 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// exit_game

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// exit_game when lose game

void	lose_game(t_game *game)
{
	ft_printf("\033[0;31mYou lost ! D:\n\033[0m");
	exit_game(game);
}

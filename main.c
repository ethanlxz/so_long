/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:51 by etlaw             #+#    #+#             */
/*   Updated: 2023/06/25 21:08:30 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_with_error(void)
{
	ft_putendl_fd("\033[0;31mError ! :(", 2);
	ft_putstr_fd("The map is invalid or the file was not found.\n", 2);
	ft_putstr_fd("The map file should be in .ber format\n\033[0m", 2);
	return (1);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (get_map(ac, av, &game))
	{
		game_init(&game);
		game_play(&game);
		mlx_loop(game.mlx);
	}
	exit_with_error();
	return (0);
}

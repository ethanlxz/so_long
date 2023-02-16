/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:51 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/16 17:44:54 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("The map is invalid or the file was not found. ", 2);
	ft_putstr_fd("Also check the file ending.", 2);
	return (1);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (get_map(ac, av, &game))
	{
		game_init(&game);
		mlx_loop(game.mlx);
	}
	exit_with_error();
	return (0);
}

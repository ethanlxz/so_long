/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:51 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/01 15:46:28 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_exit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putstr("The map is invalid or the file was not found. ");
	ft_putstr("Also check the file ending.");
	return (1);
}

int	main(int ac, char **av)
{
	t_game_map	*game_map;
	int			map_length;
	int			map_height;

	if (!get_map(ac, av, &game_map))
	{
	}
}

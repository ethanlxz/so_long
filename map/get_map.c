/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:00:02 by etlaw             #+#    #+#             */
/*   Updated: 2023/01/19 17:36:17 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map(char *filename)
{
	int		len;
	char	*filetype;

	len = ft_strlen(filename);
	filetype = &filename[(len - 4)];
	if (ft_strncmp(filetype, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	get_map(int ac, char **av, t_game_map **game_map)
{
	(*game_map) = malloc(size0f(t_game_map));
	if (ac != 1 && check_map(av[1]))
	{

	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:24:53 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/18 17:27:58 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

// from exam 02 level 4 but improvised for so_long

static void	fill(char **map, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x
		|| map[begin.y][begin.x] == '1' || map[begin.y][begin.x] == 'F')
		return ;
	map[begin.y][begin.x] = 'F';
	fill(map, size, (t_point){begin.x - 1, begin.y});
	fill(map, size, (t_point){begin.x + 1, begin.y});
	fill(map, size, (t_point){begin.x, begin.y - 1});
	fill(map, size, (t_point){begin.x, begin.y + 1});
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	fill(map, size, begin);
}
  
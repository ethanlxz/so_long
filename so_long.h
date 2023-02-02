/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:27 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/02 16:33:16 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"

typedef struct s_game_map
{
	int		map_height;
	int		map_length;
	char	**map;
	int		total_c;
}	t_game_map;

int		get_map(int argc, char *argv[], t_game_map **game_map);

#endif
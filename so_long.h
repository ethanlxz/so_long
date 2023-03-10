/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:27 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/16 17:46:40 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

//p = player , c = collectable , n = enemy, e = exit

typedef struct s_game
{
	int		map_height;
	int		map_length;
	int		img_h;
	int		img_l;
	char	**map;
	int		total_c;
	int		moves;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	void	*img_backg;
	void	*img_wall;
	void	*img_p;
	void	*img_c;
	void	*img_n;
	void	*img_e;
}	t_game;

int		get_map(int ac, char **av, t_game *game);

void	flood_fill(char **map, t_point size, t_point begin);

int		check_map(t_game *game);

void	game_init(t_game *game);

int		map_draw(t_game	*game);

int		path_checker(t_game *game);

void	flood_fill(char **map, t_point size, t_point begin);

#endif
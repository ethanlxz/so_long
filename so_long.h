/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:27 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/28 17:38:45 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"
# include <stdio.h>

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
	int		enemy_x;
	int		enemy_y;
	void	*mlx;
	void	*win;
	void	*img_backg;
	void	*img_wall;
	void	*img_p;
	void	*img_c;
	void	*img_n;
	void	*img_e;
	void	*img_rip1;
	int		c_anim;
}	t_game;

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

int		get_map(int ac, char **av, t_game *game);

void	flood_fill(char **map, t_point size, t_point begin);

int		check_map(t_game *game);

void	free_map(char **map_data, int size);

int		check_newline(t_game *game);

void	game_init(t_game *game);

void	exit_game(t_game *game);
void	lose_game(t_game *game);

int		map_draw(t_game	*game);
void	tombstone_draw(t_game *game);

void	game_play(t_game *game);

void	player_move(t_game *game, t_point move, char key);

void	enemy_move(t_game *game, t_point move, char key);

int		path_checker(t_game *game);

void	flood_fill(char **map, t_point size, t_point begin);

void	display_moves(char who, t_game *game);
void	display_title(t_game *game);

void	rip(t_game *game);

int		animation(t_game *game);

#endif
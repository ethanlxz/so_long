# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:45:00 by etlaw             #+#    #+#              #
#    Updated: 2023/06/25 21:08:58 by etlaw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long

LIBFTNAME = libft.a

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g

MINILIBX = -I /usr/X11/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit

OBJS = $(SRC:.c=.o)

SRC = main.c

SRC += ./get_map/get_map.c ./get_map/check_map.c ./get_map/floodfill.c ./get_map/valid_path.c \
			./get_map/check_map2.c


SRC += ./render_map/game_init.c ./render_map/map_draw.c ./render_map/player_move.c ./render_map/keyboard.c ./render_map/exit_game.c \
			./render_map/show_moves.c ./render_map/enemy_move.c ./render_map/animation.c

LIBFTPATH = ./libft/

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} $(OBJS) $(MAPTOOLS) ${RENDERSRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=0

clean:
	rm -rf $(OBJS)

bonus: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=1

fclean: clean
	rm -rf $(LIBFTNAME) $(NAME)

re: fclean ${NAME}
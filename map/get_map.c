/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:00:02 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/09 15:45:14 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Reads and copy the map file into a double array

int	read_map_file(char *fn,	int *height,
int *length, t_game *game)
{
	int		fd;
	char	*line;
	char	*buffer;

	line = 0;
	height = 0;
	length = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		line = ft_strjoin(line, buffer);
		free(buffer);
		height++;
	}
	game->map = ft_split(line, '\n');
	length = ft_strlen(game->map[0]);
	free(line);
	close (fd);
	return (1);
}

// Checks if the map file ends with .ber

static int	check_name(char *filename)
{
	int		len;
	char	*filetype;

	len = ft_strlen(filename);
	filetype = &filename[(len - 4)];
	if (ft_strncmp(filetype, ".ber", 4) == 0)
		return (1);
	return (0);
}

// get_map

int	get_map(int ac, char **av, t_game *game)
{
	int	map_l;
	int	map_h;

	if (ac == 2 && check_name(av[1]))
	{
		if (!read_map_file(av[1], &map_l, &map_h, game))
		{
			free(game);
			game = NULL;
			return (0);
		}
		game->map_height = map_h;
		game->map_length = map_l;
		if (check_map(game))
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:10:29 by hhervieu          #+#    #+#             */
/*   Updated: 2026/06/11 17:30:47 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	parsing_line_map(char *line)
{
	int	i;

	i = 0;
	if (is_empty_line(line))
		return (1);
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	fill_map(char *filename, t_game *game, int status, int in_map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nOpen"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
			in_map = 1;
		if (!status && in_map)
		{
			status = parsing_line_map(line);
			game->map[i++] = line;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	return (free(line), close(fd), status);
}

int	enclose_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_walkable(map[y][x]))
			{
				if (get_map_char(map, y - 1, x) == ' '
					|| get_map_char(map, y + 1, x) == ' '
					|| get_map_char(map, y, x - 1) == ' '
					|| get_map_char(map, y, x + 1) == ' ')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	nb_player(char **map)
{
	int	y;
	int	x;
	int	player_count;

	y = 0;
	player_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				player_count++;
			x++;
		}
		y++;
	}
	return (player_count);
}

int	parsing_map(char *filename, t_game *game)
{
	if (fill_map(filename, game, 0, 0))
		return (write(2, "Error\nMap:breakline or wrong character\n", 39), 1);
	if (!enclose_map(game->map))
		return (write(2, "Error\nMap:no enclose\n", 21), 1);
	if (nb_player(game->map) != 1)
		return (write(2, "Error\nMap:wrong number of player\n", 33), 1);
	parsing_player(game);
	fill_doors(game);
	return (0);
}

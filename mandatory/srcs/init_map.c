/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:58:19 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/24 18:34:25 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	color_to_zero(t_game *game)
{
	game->color->ceiling->red = -1;
	game->color->ceiling->green = -1;
	game->color->ceiling->blue = -1;
	game->color->floor->red = -1;
	game->color->floor->green = -1;
	game->color->floor->blue = -1;
}

void	map_to_null(t_game *game, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		game->map[i] = NULL;
		i++;
	}
}

int	init_map(char *filename, t_game *game, int count)
{
	int		fd;
	char	*line;
	int		in_map;

	in_map = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nOpen"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_char(line[0]))
			in_map = 1;
		if (in_map)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map = malloc(sizeof(char *) * (count + 1));
	if (!game->map)
		return (perror("Error\nMap"), 1);
	map_to_null(game, count + 1);
	return (close(fd), 0);
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_coord));
	if (!game->player)
	{
		perror("Error\nplayer");
		exit_game(game, 1);
	}
	game->player->x = -1;
	game->player->y = -1;
	game->player->ply_dir_x = -1;
	game->player->ply_dir_y = -1;
}

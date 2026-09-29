/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:49:22 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:19:37 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	parsing_line(char *line, t_game *game)
{
	int	ret;

	if (is_empty_line(line))
		return (0);
	ret = parsing_line2(line, game);
	if (ret != -1)
		return (ret);
	ret = parsing_line3(line, game);
	if (ret != -1)
		return (ret);
	if (line[0] == 'F' && line[1] == ' ')
		return (parsing_color(line, game->color->floor));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parsing_color(line, game->color->ceiling));
	else if (is_map_line(line))
		return (2);
	else
		return (write(2, "Error\nIncorrect color and texture info\n", 39), 1);
}

int	parsing_line2(char *line, t_game *game)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->no));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->so));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->we));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->ea));
	else if (line[0] == 'L' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->lo));
	else if (line[0] == 'G' && line[1] == 'R' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->gr));
	else if (line[0] == 'B' && line[1] == 'L' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->bl));
	else if (line[0] == 'P' && line[1] == 'U' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->pu));
	else if (line[0] == 'R' && line[1] == 'E' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->re));
	else if (line[0] == 'O' && line[1] == 'R' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->or));
	else if (line[0] == 'Y' && line[1] == 'E' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->ye));
	else if (line[0] == 'A' && line[1] == 'L' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->al));
	return (-1);
}

int	parsing_line3(char *line, t_game *game)
{
	if (line[0] == 'L' && line[1] == 'I' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->lig));
	else if (line[0] == 'T' && line[1] == 'I' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->ton));
	else if (line[0] == 'T' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->tof));
	else if (line[0] == 'T' && line[1] == 'B' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->rti));
	else if (line[0] == 'T' && line[1] == 'A' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->rto));
	else if (line[0] == 'M' && line[1] == 'A' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->m_a));
	else if (line[0] == 'M' && line[1] == 'B' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->m_b));
	else if (line[0] == 'D' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->doo));
	else if (line[0] == 'D' && line[1] == 'I' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->doi));
	else if (line[0] == 'S' && line[1] == 'T' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->st));
	return (-1);
}

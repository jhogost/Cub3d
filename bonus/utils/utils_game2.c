/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:30:39 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/09 17:29:41 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_map_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	get_map_char(char **map, int y, int x)
{
	if (y < 0 || x < 0)
		return (' ');
	if (!map[y])
		return (' ');
	if (x >= (int)ft_strlen(map[y]))
		return (' ');
	return (map[y][x]);
}

char	get_player_direction(t_coord *player)
{
	if (fabs(player->ply_dir_x) > fabs(player->ply_dir_y))
	{
		if (player->ply_dir_x > 0)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (player->ply_dir_y > 0)
			return ('S');
		else
			return ('N');
	}
}

int	get_sprite_from_pos(t_sprite *sprites, int max_sprite, int x, int y)
{
	while (max_sprite >= 0)
	{
		if ((int)sprites[max_sprite].x == x && (int)sprites[max_sprite].y == y)
			return (max_sprite);
		max_sprite--;
	}
	return (-1);
}

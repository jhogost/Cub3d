/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:54:29 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/21 12:39:23 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	is_walkable(char c)
{
	if (c == '0' || is_player(c))
		return (1);
	else
		return (0);
}

int	is_map_char(char c)
{
	if (c == ' ' || c == '1' || is_walkable(c))
		return (1);
	else
		return (0);
}

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_map_char(str[i]))
			return (0);
		i ++;
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

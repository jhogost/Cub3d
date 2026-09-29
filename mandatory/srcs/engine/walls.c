/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:25:03 by hhervieu          #+#    #+#             */
/*   Updated: 2026/05/26 14:25:03 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

int	walls_border(char **map, double x, double y, char c)
{
	double	r;
	int		xi;
	int		yi;

	r = 0.33;
	xi = floor(x + r);
	yi = floor(y - r);
	c = get_map_char(map, yi, xi);
	if (!is_walkable(c))
		return (0);
	xi = floor(x - r);
	yi = floor(y + r);
	c = get_map_char(map, yi, xi);
	if (!is_walkable(c))
		return (0);
	xi = floor(x - r);
	yi = floor(y - r);
	c = get_map_char(map, yi, xi);
	if (!is_walkable(c))
		return (0);
	return (1);
}

int	can_walk(char **map, double x, double y)
{
	char	c;
	double	r;
	int		xi;
	int		yi;

	r = 0.33;
	c = get_map_char(map, (int)y, (int)x);
	if (!is_walkable(c))
		return (0);
	xi = floor(x + r);
	yi = floor(y + r);
	c = get_map_char(map, yi, xi);
	if (!is_walkable(c))
		return (0);
	if (walls_border(map, x, y, c) == 0)
		return (0);
	return (1);
}

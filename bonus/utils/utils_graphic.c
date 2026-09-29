/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:08:37 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 10:45:13 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	create_rgb(t_pixel *pixel)
{
	int	r;
	int	g;
	int	b;

	r = pixel->red;
	g = pixel->green;
	b = pixel->blue;
	return (r << 16 | g << 8 | b);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH)
		return ;
	if (y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_x_position_minimap(t_game *game)
{
	if (game->stage == 0 || game->stage == 1)
		return (-20);
	if (game->stage == 2)
		return (-14);
	return (0);
}

int	get_y_position_minimap(t_game *game)
{
	if (game->stage == 0 || game->stage == 1)
		return (35);
	if (game->stage == 2)
		return (15);
	if (game->stage == 5)
		return (95);
	return (0);
}

int	find_square_color(t_game *game, int x, int y)
{
	if (game->map[y][x] == '8' || game->map[y][x] == '9')
		return (0xef4444);
	else if (is_wall_char(game->map[y][x]))
		return (0x00babc);
	else if (is_walkable(game->map[y][x]))
	{
		if ((game->map[y][x] == 'u' || game->map[y][x] == 'v')
			&& game->moulinette_find)
			return (0x5E00CC);
		else
			return (0x6c6c6c);
	}
	return (0);
}

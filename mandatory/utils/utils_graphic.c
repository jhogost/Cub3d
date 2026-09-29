/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:08:37 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/26 11:33:15 by jbayet           ###   ########.fr       */
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

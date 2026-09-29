/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:28:48 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:25:23 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

static t_img	*get_alpha_texture(t_textures *textures, char c)
{
	if (c == 'a')
		return (textures->gr);
	else if (c == 'b')
		return (textures->bl);
	else if (c == 'c')
		return (textures->pu);
	else if (c == 'd')
		return (textures->re);
	else if (c == 'e')
		return (textures->or);
	else if (c == 'f')
		return (textures->ye);
	else if (c == 'g')
		return (textures->al);
	else if (c == 'h')
		return (textures->lo);
	else
		return (textures->st);
}

static t_img	*get_force_horiz_texture(t_textures *textures, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (textures->so);
		return (textures->no);
	}
	if (ray->ray_dir_y > 0)
		return (textures->so);
	return (textures->no);
}

static t_img	*get_door_texture(t_textures *textures, char c)
{
	if (c == '8')
		return (textures->doi);
	else
		return (textures->doo);
}

t_img	*get_texture(t_game *game, t_ray *ray)
{
	char	c;

	c = game->map[ray->map_y][ray->map_x];
	if (c >= 'a' && c <= 'z')
		return (get_alpha_texture(game->textures, c));
	if (is_door_char(c))
		return (get_door_texture(game->textures, c));
	if (c == '2')
		return (get_force_horiz_texture(game->textures, ray));
	if (c == '3')
	{
		if (ray->ray_dir_y > 0)
			return (game->textures->ea);
		return (game->textures->we);
	}
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (game->textures->ea);
		return (game->textures->we);
	}
	if (ray->ray_dir_y > 0)
		return (game->textures->so);
	return (game->textures->no);
}

int	get_tex_color(t_img *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:28:48 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/25 19:03:31 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

t_img	*get_texture(t_game *game, t_ray *ray)
{
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

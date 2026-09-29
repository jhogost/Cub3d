/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:28:13 by hhervieu          #+#    #+#             */
/*   Updated: 2026/06/10 11:28:13 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	check_door_hit(t_game *game, t_ray *ray, int *hit)
{
	t_door	*door;
	double	p_dist;
	double	h_coord;

	door = get_door_at(game, ray->map_x, ray->map_y);
	p_dist = ray->side_dist_y - ray->delta_dist_y / 2.0;
	h_coord = game->player->x + p_dist * ray->ray_dir_x;
	if (ray->side == 0)
	{
		p_dist = ray->side_dist_x - ray->delta_dist_x / 2.0;
		h_coord = game->player->y + p_dist * ray->ray_dir_y;
	}
	if ((ray->side == 0 && (int)h_coord != ray->map_y)
		|| (ray->side == 1 && (int)h_coord != ray->map_x))
		return ;
	h_coord -= floor(h_coord);
	if (door && h_coord < door->offset)
		return ;
	if (ray->side == 0)
		ray->side_dist_x = p_dist + ray->delta_dist_x;
	else
		ray->side_dist_y = p_dist + ray->delta_dist_y;
	*hit = 1;
}

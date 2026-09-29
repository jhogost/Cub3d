/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:03:28 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/25 18:22:06 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	init_ray(t_game *game, t_ray *ray, int col)
{
	ray->sensor_col = ray->sensor_div * col - 1;
	ray->ray_dir_x = game->player->ply_dir_x
		+ game->player->sensor_x * ray->sensor_col;
	ray->ray_dir_y = game->player->ply_dir_y
		+ game->player->sensor_y * ray->sensor_col;
	ray->map_x = (int)game->player->x;
	ray->map_y = (int)game->player->y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = DBL_MAX;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = DBL_MAX;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	init_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player->y)
			* ray->delta_dist_y;
	}
}

void	dda(t_game *game, t_ray *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_dist);
	ray->draw_start = (WIN_HEIGHT - ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->draw_start + ray->line_height;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->x_hit = game->player->y + ray->perp_dist * ray->ray_dir_y;
	else
		ray->x_hit = game->player->x + ray->perp_dist * ray->ray_dir_x;
	ray->x_hit -= floor(ray->x_hit);
}

void	draw_wall(t_game *game, t_img *img, t_ray *ray, int col)
{
	t_img	*tex;
	double	step;
	int		color;

	tex = get_texture(game, ray);
	ray->tex_x = (int)(ray->x_hit * (double)TEXTURE_SIZE);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		ray->tex_x = TEXTURE_SIZE - ray->tex_x - 1;
	step = (double)TEXTURE_SIZE / (double)ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* step;
	while (ray->draw_start <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= TEXTURE_SIZE)
			ray->tex_y = TEXTURE_SIZE - 1;
		color = get_tex_color(tex, ray->tex_x, ray->tex_y);
		put_pixel(img, col, ray->draw_start, color);
		ray->tex_pos += step;
		ray->draw_start++;
	}
}

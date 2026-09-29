/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:22:04 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/27 18:24:22 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	draw_floor_and_ceiling(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	half;

	half = WIN_HEIGHT / 2;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < half)
				put_pixel(img, x, y, game->color->ceiling_pixel);
			else
				put_pixel(img, x, y, game->color->floor_pixel);
			x++;
		}
		y++;
	}
}

void	raycast_scene(t_game *game, t_img *img)
{
	t_ray	ray;
	int		col;

	ray.sensor_div = 2 / (double)WIN_WIDTH;
	col = 0;
	while (col < WIN_WIDTH)
	{
		init_ray(game, &ray, col);
		init_step(game, &ray);
		dda(game, &ray);
		calculate_wall(game, &ray);
		draw_wall(game, img, &ray, col);
		col++;
	}
}

int	render_frame(t_game *game)
{
	struct timeval	new_time_limit;

	gettimeofday(&new_time_limit, NULL);
	if (new_time_limit.tv_sec * 1000000 + new_time_limit.tv_usec
		< game->time_fps_limit.tv_sec * 1000000 + game->time_fps_limit.tv_usec
		+ (1000000 / FPS_LIMIT))
		return (0);
	else
		gettimeofday(&game->time_fps_limit, NULL);
	update_player(game);
	draw_floor_and_ceiling(game, game->img);
	raycast_scene(game, game->img);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
	return (0);
}

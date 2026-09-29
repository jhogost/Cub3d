/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:24:35 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/08 17:17:31 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

int	get_sprite_transform(t_game *game, t_sprite *sprite, t_sprite_draw *draw)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = sprite->x - game->player->x;
	sprite_y = sprite->y - game->player->y;
	inv_det = 1.0 / (game->player->sensor_x * game->player->ply_dir_y
			- game->player->ply_dir_x * game->player->sensor_y);
	draw->transform_x = inv_det * (game->player->ply_dir_y * sprite_x
			- game->player->ply_dir_x * sprite_y);
	draw->transform_y = inv_det * (-game->player->sensor_y * sprite_x
			+ game->player->sensor_x * sprite_y);
	return (draw->transform_y > 0.0001);
}

void	get_sprite_bounds(t_sprite_draw *draw)
{
	draw->screen_x = (int)((WIN_WIDTH / 2.0)
			* (1 + draw->transform_x / draw->transform_y));
	draw->height = abs((int)(WIN_HEIGHT / draw->transform_y));
	draw->width = draw->height;
	draw->start_y = -draw->height / 2 + WIN_HEIGHT / 2;
	draw->end_y = draw->height / 2 + WIN_HEIGHT / 2;
	draw->start_x = -draw->width / 2 + draw->screen_x;
	draw->end_x = draw->width / 2 + draw->screen_x;
}

void	clip_sprite(t_sprite_draw *draw)
{
	if (draw->start_y < 0)
		draw->start_y = 0;
	if (draw->end_y >= WIN_HEIGHT)
		draw->end_y = WIN_HEIGHT - 1;
}

void	draw_sprite_col(t_game *game, t_sprite_draw *draw, int col, t_img *img)
{
	int		y;
	int		pix;
	double	step;
	double	tex_pos;

	draw->tex_x = (int)((col - (-draw->width / 2 + draw->screen_x))
			* TEXTURE_SIZE / (double)draw->width);
	step = (double)TEXTURE_SIZE / draw->height;
	tex_pos = (draw->start_y - WIN_HEIGHT / 2 + draw->height / 2) * step;
	y = draw->start_y;
	while (y < draw->end_y)
	{
		draw->tex_y = (int)tex_pos;
		if (draw->tex_y >= 0 && draw->tex_y < TEXTURE_SIZE)
		{
			pix = get_tex_color(img, draw->tex_x, draw->tex_y);
			if (pix != 0x00FF00)
				put_pixel(game->img, col, y, pix);
		}
		tex_pos += step;
		y++;
	}
}

void	draw_one_sprite(t_game *game, t_sprite *sprite, t_img *img)
{
	t_sprite_draw	draw;
	int				stripe;

	if (!get_sprite_transform(game, sprite, &draw))
		return ;
	get_sprite_bounds(&draw);
	clip_sprite(&draw);
	stripe = draw.start_x;
	while (stripe < draw.end_x)
	{
		if (draw.transform_y > 0 && stripe >= 0 && stripe < WIN_WIDTH
			&& draw.transform_y < game->zbuffer[stripe])
			draw_sprite_col(game, &draw, stripe, img);
		stripe++;
	}
}

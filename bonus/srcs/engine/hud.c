/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:53:36 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 19:31:31 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	draw_hud(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 23)
	{
		x = 0;
		while (x < 1065)
		{
			color = get_tex_color(game->textures->hud, x, y);
			if (color != 0x00FF00)
				put_pixel(game->img, STAGE_X + x, STAGE_Y + y, color);
			x++;
		}
		y++;
	}
	draw_red_step(game);
	draw_minimap(game, MINIMAP_X + get_x_position_minimap(game),
		MINIMAP_Y + get_y_position_minimap(game));
}

void	draw_minimap(t_game *game, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			color = find_square_color(game, x, y);
			if (color)
				draw_square(game, pos_x + x * 7, pos_y + y * 7, color);
			x++;
		}
		y++;
		draw_square(game, pos_x + (int)game->player->x * 7,
			pos_y + (int)game->player->y * 7, 0xffffff);
	}
}

void	draw_square(t_game *game, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if (y == 0 || y == 7 || x == 0 || x == 7)
				put_pixel(game->img, x_start + x, y_start + y, 0x000000);
			else
				put_pixel(game->img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}

void	draw_red_step(t_game *game)
{
	int	x;

	if (game->stage == 0)
		x = 105;
	else if (game->stage == 1)
		x = 267;
	else if (game->stage == 2)
		x = 460;
	else if (game->stage == 3)
		x = 680;
	else if (game->stage == 4)
		x = 870;
	else if (game->stage == 5)
		x = 1015;
	draw_red_line(game, x);
}

void	draw_red_line(t_game *game, int strtx)
{
	int	x;
	int	y;

	y = 0;
	while (y < 42)
	{
		x = 0;
		while (x < 2)
		{
			if (y == 0 || y == 4)
			{
				put_pixel(game->img, strtx + x - 1, STAGE_Y - 10 + y, 0xef4444);
				put_pixel(game->img, strtx + x + 1, STAGE_Y - 10 + y, 0xef4444);
			}
			if (y == 1 || y == 2 || y == 3)
			{
				put_pixel(game->img, strtx + x - 2, STAGE_Y - 10 + y, 0xef4444);
				put_pixel(game->img, strtx + x + 2, STAGE_Y - 10 + y, 0xef4444);
			}
			put_pixel(game->img, strtx + x, STAGE_Y - 10 + y, 0xef4444);
			x++;
		}
		y++;
	}
}

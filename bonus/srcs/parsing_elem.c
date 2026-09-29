/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:24:40 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/24 18:34:25 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

static void	get_player_dir(char c, t_coord *player)
{
	if (c == 'N')
	{
		player->ply_dir_x = 0;
		player->ply_dir_y = -1;
	}
	else if (c == 'E')
	{
		player->ply_dir_x = 1;
		player->ply_dir_y = 0;
	}
	else if (c == 'S')
	{
		player->ply_dir_x = 0;
		player->ply_dir_y = 1;
	}
	else if (c == 'W')
	{
		player->ply_dir_x = -1;
		player->ply_dir_y = 0;
	}
}

void	parsing_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_player(game->map[y][x]))
			{
				game->player->x = x + 0.5;
				game->player->y = y + 0.5;
				get_player_dir(game->map[y][x], game->player);
				game->player->sensor_x = -game->player->ply_dir_y * FOV;
				game->player->sensor_y = game->player->ply_dir_x * FOV;
			}
			x++;
		}
		y++;
	}
}

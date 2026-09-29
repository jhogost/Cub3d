/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:10:08 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/08 20:16:45 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	count_sprites(char **map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_sprite_char(map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	fill_sprites(t_game *game)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_sprite_char(game->map[y][x]))
			{
				game->sprites[i].id = game->map[y][x];
				game->sprites[i].status = 0;
				game->sprites[i].x = x + 0.5;
				game->sprites[i].y = y + 0.5;
				game->sprites[i].dist = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_sprites(t_game *game)
{
	game->sprite_count = count_sprites(game->map);
	if (game->sprite_count <= 0)
	{
		game->sprites = NULL;
		return ;
	}
	game->sprites = malloc(sizeof(t_sprite) * game->sprite_count);
	if (!game->sprites)
	{
		perror("Error\nsprite");
		exit_game(game, 1);
	}
	fill_sprites(game);
}

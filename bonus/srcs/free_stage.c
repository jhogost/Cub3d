/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 14:23:08 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 08:04:04 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	free_color(t_game *game)
{
	if (game->color)
	{
		if (game->color->floor)
			free(game->color->floor);
		if (game->color->ceiling)
			free(game->color->ceiling);
		free(game->color);
		game->color = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	free_textures(t_game *game)
{
	if (game->textures)
	{
		free_textures_part1(game);
		free_textures_part2(game);
		free_textures_part3(game);
		free_textures_part4(game);
		free_textures_part5(game);
		free_textures_part6(game);
		free(game->textures);
		game->textures = NULL;
	}
}

void	free_stage(t_game *game)
{
	if (game->doors)
		free(game->doors);
	game->doors = NULL;
	if (game->player)
		free(game->player);
	game->player = NULL;
	if (game->sprites)
		free(game->sprites);
	game->sprites = NULL;
	free_color(game);
	free_map(game);
	free_textures(game);
}

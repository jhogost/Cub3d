/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:14:15 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/27 17:58:29 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	free_textures(t_game *game)
{
	if (game->textures)
	{
		free_textures_part1(game);
		free_textures_part2(game);
		free(game->textures);
	}
}

void	free_color(t_game *game)
{
	if (game->color)
	{
		if (game->color->floor)
			free(game->color->floor);
		if (game->color->ceiling)
			free(game->color->ceiling);
		free(game->color);
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
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_textures(game);
		free_color(game);
		free_map(game);
		if (game->player)
			free(game->player);
		if (game->img)
		{
			if (game->img->img_ptr)
				mlx_destroy_image(game->mlx, game->img->img_ptr);
			free(game->img);
		}
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	free(game);
}

void	exit_game(t_game *game, int out)
{
	free_game(game);
	exit(out);
}

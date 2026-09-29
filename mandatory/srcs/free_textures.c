/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:55:51 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/27 18:24:57 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	free_textures_part1(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->no)
		{
			if (game->textures->no->img_ptr)
				mlx_destroy_image(game->mlx, game->textures->no->img_ptr);
			free(game->textures->no);
		}
		if (game->textures->so)
		{
			if (game->textures->so->img_ptr)
				mlx_destroy_image(game->mlx, game->textures->so->img_ptr);
			free(game->textures->so);
		}
		if (game->textures->we)
		{
			if (game->textures->we->img_ptr)
				mlx_destroy_image(game->mlx, game->textures->we->img_ptr);
			free(game->textures->we);
		}
	}
}

void	free_textures_part2(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->ea)
		{
			if (game->textures->ea->img_ptr)
				mlx_destroy_image(game->mlx, game->textures->ea->img_ptr);
			free(game->textures->ea);
		}
	}
}

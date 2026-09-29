/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:55:42 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:17:15 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	free_textures_part6(t_game *game)
{
	if (game->textures->rti)
	{
		if (game->textures->rti->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->rti->img_ptr);
		free(game->textures->rti);
	}
	if (game->textures->rto)
	{
		if (game->textures->rto->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->rto->img_ptr);
		free(game->textures->rto);
	}
	if (game->textures->st)
	{
		if (game->textures->st->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->st->img_ptr);
		free(game->textures->st);
	}
}

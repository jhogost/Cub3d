/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:55:51 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/08 17:12:57 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	free_textures_part1(t_game *game)
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
	if (game->textures->ea)
	{
		if (game->textures->ea->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->ea->img_ptr);
		free(game->textures->ea);
	}
}

void	free_textures_part2(t_game *game)
{
	if (game->textures->lo)
	{
		if (game->textures->lo->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->lo->img_ptr);
		free(game->textures->lo);
	}
	if (game->textures->gr)
	{
		if (game->textures->gr->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->gr->img_ptr);
		free(game->textures->gr);
	}
	if (game->textures->bl)
	{
		if (game->textures->bl->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->bl->img_ptr);
		free(game->textures->bl);
	}
	if (game->textures->pu)
	{
		if (game->textures->pu->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->pu->img_ptr);
		free(game->textures->pu);
	}
}

void	free_textures_part3(t_game *game)
{
	if (game->textures->re)
	{
		if (game->textures->re->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->re->img_ptr);
		free(game->textures->re);
	}
	if (game->textures->or)
	{
		if (game->textures->or->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->or->img_ptr);
		free(game->textures->or);
	}
	if (game->textures->ye)
	{
		if (game->textures->ye->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->ye->img_ptr);
		free(game->textures->ye);
	}
	if (game->textures->al)
	{
		if (game->textures->al->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->al->img_ptr);
		free(game->textures->al);
	}
}

void	free_textures_part4(t_game *game)
{
	if (game->textures->hud)
	{
		if (game->textures->hud->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->hud->img_ptr);
		free(game->textures->hud);
	}
	if (game->textures->lig)
	{
		if (game->textures->lig->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->lig->img_ptr);
		free(game->textures->lig);
	}
	if (game->textures->ton)
	{
		if (game->textures->ton->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->ton->img_ptr);
		free(game->textures->ton);
	}
	if (game->textures->tof)
	{
		if (game->textures->tof->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->tof->img_ptr);
		free(game->textures->tof);
	}
}

void	free_textures_part5(t_game *game)
{
	if (game->textures->m_a)
	{
		if (game->textures->m_a->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->m_a->img_ptr);
		free(game->textures->m_a);
	}
	if (game->textures->m_b)
	{
		if (game->textures->m_b->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->m_b->img_ptr);
		free(game->textures->m_b);
	}
	if (game->textures->doo)
	{
		if (game->textures->doo->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->doo->img_ptr);
		free(game->textures->doo);
	}
	if (game->textures->doi)
	{
		if (game->textures->doi->img_ptr)
			mlx_destroy_image(game->mlx, game->textures->doi->img_ptr);
		free(game->textures->doi);
	}
}

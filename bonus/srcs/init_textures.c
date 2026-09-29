/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:20:49 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/08 16:08:48 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_textu_img_part1(t_textures *textures, t_game *game)
{
	textures->no = malloc(sizeof(t_img));
	if (!textures->no)
	{
		perror("Error\nno img");
		exit_game(game, 1);
	}
	textures->so = malloc(sizeof(t_img));
	if (!textures->so)
	{
		perror("Error\nso img");
		exit_game(game, 1);
	}
	textures->we = malloc(sizeof(t_img));
	if (!textures->we)
	{
		perror("Error\nwe img");
		exit_game(game, 1);
	}
	textures->ea = malloc(sizeof(t_img));
	if (!textures->ea)
	{
		perror("Error\nea img");
		exit_game(game, 1);
	}
}

void	init_textu_img_part2(t_textures *textures, t_game *game)
{
	textures->lo = malloc(sizeof(t_img));
	if (!textures->lo)
	{
		perror("Error\nlo img");
		exit_game(game, 1);
	}
	textures->gr = malloc(sizeof(t_img));
	if (!textures->gr)
	{
		perror("Error\ngr img");
		exit_game(game, 1);
	}
	textures->bl = malloc(sizeof(t_img));
	if (!textures->bl)
	{
		perror("Error\nbl img");
		exit_game(game, 1);
	}
	textures->pu = malloc(sizeof(t_img));
	if (!textures->pu)
	{
		perror("Error\npu img");
		exit_game(game, 1);
	}
}

void	init_textu_img_part3(t_textures *textures, t_game *game)
{
	textures->re = malloc(sizeof(t_img));
	if (!textures->re)
	{
		perror("Error\nre img");
		exit_game(game, 1);
	}
	textures->or = malloc(sizeof(t_img));
	if (!textures->or)
	{
		perror("Error\nor img");
		exit_game(game, 1);
	}
	textures->ye = malloc(sizeof(t_img));
	if (!textures->ye)
	{
		perror("Error\nye img");
		exit_game(game, 1);
	}
	textures->al = malloc(sizeof(t_img));
	if (!textures->al)
	{
		perror("Error\nal img");
		exit_game(game, 1);
	}
}

void	init_textu_img_part4(t_textures *textures, t_game *game)
{
	textures->hud = malloc(sizeof(t_img));
	if (!textures->hud)
	{
		perror("Error\nhud img");
		exit_game(game, 1);
	}
	textures->lig = malloc(sizeof(t_img));
	if (!textures->lig)
	{
		perror("Error\nlig img");
		exit_game(game, 1);
	}
	textures->ton = malloc(sizeof(t_img));
	if (!textures->ton)
	{
		perror("Error\nton img");
		exit_game(game, 1);
	}
	textures->tof = malloc(sizeof(t_img));
	if (!textures->tof)
	{
		perror("Error\ntof img");
		exit_game(game, 1);
	}
}

void	init_textu_img_part5(t_textures *textures, t_game *game)
{
	textures->m_a = malloc(sizeof(t_img));
	if (!textures->m_a)
	{
		perror("Error\nm_a img");
		exit_game(game, 1);
	}
	textures->m_b = malloc(sizeof(t_img));
	if (!textures->m_b)
	{
		perror("Error\nm_b img");
		exit_game(game, 1);
	}
	textures->doo = malloc(sizeof(t_img));
	if (!textures->doo)
	{
		perror("Error\ndoo img");
		exit_game(game, 1);
	}
	textures->doi = malloc(sizeof(t_img));
	if (!textures->doi)
	{
		perror("Error\ndoi img");
		exit_game(game, 1);
	}
}

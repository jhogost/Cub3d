/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:38:12 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/25 16:51:45 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_textu_img_data(t_textures *textures)
{
	textures->no->img_ptr = NULL;
	textures->no->addr = NULL;
	textures->so->img_ptr = NULL;
	textures->so->addr = NULL;
	textures->we->img_ptr = NULL;
	textures->we->addr = NULL;
	textures->ea->img_ptr = NULL;
	textures->ea->addr = NULL;
}

void	init_textu_img(t_textures *textures, t_game *game)
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
	init_textu_img_data(textures);
}

void	init_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
	{
		perror("Error\ntextures");
		exit_game(game, 1);
	}
	game->textures->no = NULL;
	game->textures->so = NULL;
	game->textures->we = NULL;
	game->textures->ea = NULL;
	init_textu_img(game->textures, game);
}

void	init_color(t_game *game)
{
	game->color = malloc(sizeof(t_color));
	if (!game->color)
	{
		perror("Error\ntextures");
		exit_game(game, 1);
	}
	game->color->floor = NULL;
	game->color->ceiling = NULL;
	game->color->floor = malloc(sizeof(t_pixel));
	if (!game->color->floor)
	{
		perror("Error\nfloor");
		exit_game(game, 1);
	}
	game->color->ceiling = malloc(sizeof(t_pixel));
	if (!game->color->ceiling)
	{
		perror("Error\nceilling");
		exit_game(game, 1);
	}
	color_to_zero(game);
}

void	init_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
	{
		perror("Error\nimg");
		exit_game(game, 1);
	}
	game->img->img_ptr = NULL;
	game->img->addr = NULL;
	game->img->img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img->img_ptr)
	{
		write(2, "Error\nmlx_new_image failed\n", 27);
		exit_game(game, 1);
	}
	game->img->addr = mlx_get_data_addr(
			game->img->img_ptr,
			&game->img->bpp,
			&game->img->line_length,
			&game->img->endian);
	if (!game->img->addr)
	{
		write(2, "Error\nmlx_get_data_addr failed\n", 31);
		exit_game(game, 1);
	}
}

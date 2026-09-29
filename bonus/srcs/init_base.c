/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:38:12 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:17:37 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

static void	textures_to_null(t_game *game)
{
	game->textures->no = NULL;
	game->textures->so = NULL;
	game->textures->we = NULL;
	game->textures->ea = NULL;
	game->textures->lo = NULL;
	game->textures->gr = NULL;
	game->textures->bl = NULL;
	game->textures->pu = NULL;
	game->textures->re = NULL;
	game->textures->or = NULL;
	game->textures->ye = NULL;
	game->textures->al = NULL;
	game->textures->lig = NULL;
	game->textures->hud = NULL;
	game->textures->ton = NULL;
	game->textures->tof = NULL;
	game->textures->m_a = NULL;
	game->textures->m_b = NULL;
	game->textures->doo = NULL;
	game->textures->doi = NULL;
	game->textures->rti = NULL;
	game->textures->rto = NULL;
	game->textures->st = NULL;
}

void	init_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
	{
		perror("Error\ntextures");
		exit_game(game, 1);
	}
	textures_to_null(game);
	init_textu_img_part1(game->textures, game);
	init_textu_img_part2(game->textures, game);
	init_textu_img_part3(game->textures, game);
	init_textu_img_part4(game->textures, game);
	init_textu_img_part5(game->textures, game);
	init_textu_img_part6(game->textures, game);
	init_textu_img_data_part1(game->textures);
	init_textu_img_data_part2(game->textures);
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

void	init_hud(t_game *game, t_img *texture)
{
	int	x;
	int	y;

	x = 1065;
	y = 23;
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/hud.xpm", &x, &y);
	if (!texture->img_ptr)
	{
		write(2, "Error\nFailed to load textures: hud\n", 35);
		exit_game(game, 1);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		write(2, "Error\nmlx_get_data_addr hud failed\n", 31);
		exit_game(game, 1);
	}
}

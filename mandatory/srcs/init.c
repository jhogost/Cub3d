/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:51:22 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/27 18:19:46 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_graphic(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nmlx_init failed\n", 22);
		exit_game(game, 1);
	}
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
	{
		write(2, "Error\nmlx_new_window failed\n", 28);
		exit_game(game, 1);
	}
	init_img(game);
}

void	init_game(t_game **game)
{
	int	i;

	*game = malloc(sizeof(t_game));
	if (!(*game))
	{
		perror("Error\ngame");
		exit_game(*game, 1);
	}
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	(*game)->textures = NULL;
	(*game)->color = NULL;
	(*game)->map = NULL;
	(*game)->player = NULL;
	i = 0;
	while (i < INPUT_COUNT)
		(*game)->input[i++] = 0;
	gettimeofday(&(*game)->time_fps_limit, NULL);
}

void	init(char *filename, t_game **game)
{
	init_game(game);
	init_graphic(*game);
	init_textures(*game);
	init_color(*game);
	init_player(*game);
	if (init_map(filename, *game, 0))
		exit_game(*game, 1);
	if (parsing_textu_color(filename, *game) == 1)
		exit_game(*game, 1);
	if (missing_info(*game))
	{
		write(2, "Error\nColor and/or texture information missing\n", 47);
		exit_game(*game, 1);
	}
	if (parsing_map(filename, *game))
		exit_game(*game, 1);
}

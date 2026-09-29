/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:51:22 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 11:51:26 by jbayet           ###   ########.fr       */
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
	init_mouse(game);
}

void	game_to_null(t_game *game)
{
	int	i;

	(game)->mlx = NULL;
	(game)->win = NULL;
	(game)->textures = NULL;
	(game)->color = NULL;
	(game)->map = NULL;
	(game)->player = NULL;
	(game)->sprites = NULL;
	(game)->img = NULL;
	(game)->doors = NULL;
	(game)->stage = 0;
	(game)->fps = 0;
	(game)->moulinette_find = 0;
	i = 0;
	while (i < INPUT_COUNT)
		(game)->input[i++] = 0;
	(game)->frame = 0;
	gettimeofday(&(game)->time_fps_control, NULL);
	gettimeofday(&(game)->time_fps_limit, NULL);
	(game)->mouse_x = 0;
	(game)->mouse_y = 0;
	(game)->mouse_locked = 0;
}

void	init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
	{
		perror("Error\ngame");
		exit_game(*game, 1);
	}
	game_to_null(*game);
}

static void	init_level(char *filename, t_game *game)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '1')
			game->stage = 1;
		if (filename[i] == '2')
			game->stage = 2;
		if (filename[i] == '4')
			game->stage = 3;
		if (filename[i] == '6')
			game->stage = 4;
		if (filename[i] == '7')
			game->stage = 5;
		i++;
	}
}

void	init(char *filename, t_game **game)
{
	init_game(game);
	init_graphic(*game);
	init_textures(*game);
	init_color(*game);
	init_player(*game);
	init_doors(*game);
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
	init_hud(*game, (*game)->textures->hud);
	init_sprites(*game);
	init_level(filename, *game);
}

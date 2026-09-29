/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 07:42:12 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 10:34:20 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_stage(char *filename, t_game *game)
{
	init_textures(game);
	init_color(game);
	init_player(game);
	init_doors(game);
	if (init_map(filename, game, 0))
		exit_game(game, 1);
	if (parsing_textu_color(filename, game) == 1)
		exit_game(game, 1);
	if (missing_info(game))
	{
		write(2, "Error\nColor and/or texture information missing\n", 47);
		exit_game(game, 1);
	}
	if (parsing_map(filename, game))
		exit_game(game, 1);
	init_hud(game, (game)->textures->hud);
	init_sprites(game);
	game->moulinette_find = 0;
}

void	init_next_stage(t_game *game)
{
	if (game->stage == 1)
		init_stage("./bonus/maps/map_stage_1.cub", game);
	else if (game->stage == 2)
		init_stage("./bonus/maps/map_stage_2.cub", game);
	else if (game->stage == 3)
		init_stage("./bonus/maps/map_stage_4.cub", game);
	else if (game->stage == 4)
		init_stage("./bonus/maps/map_stage_6.cub", game);
	else if (game->stage == 5)
		init_stage("./bonus/maps/map_stage_7.cub", game);
	else
	{
		printf("YOU WIN !!\n");
		exit_game(game, 0);
	}
}

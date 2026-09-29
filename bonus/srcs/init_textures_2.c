/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:00:02 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:18:56 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_textu_img_part6(t_textures *textures, t_game *game)
{
	textures->rti = malloc(sizeof(t_img));
	if (!textures->rti)
	{
		perror("Error\nrti img");
		exit_game(game, 1);
	}
	textures->rto = malloc(sizeof(t_img));
	if (!textures->rto)
	{
		perror("Error\nrto img");
		exit_game(game, 1);
	}
	textures->st = malloc(sizeof(t_img));
	if (!textures->st)
	{
		perror("Error\nst img");
		exit_game(game, 1);
	}
}

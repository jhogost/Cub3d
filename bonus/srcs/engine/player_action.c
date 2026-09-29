/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:40:29 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 15:41:20 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	terminal_switch(t_game *game, int x, int y)
{
	int	i;

	i = get_sprite_from_pos(game->sprites, game->sprite_count - 1, x, y);
	if (i == -1)
		return ;
	game->sprites[i].status = !game->sprites[i].status;
}

void	action_player(t_game *game)
{
	int	target_x;
	int	target_y;

	if (get_target(game, game->player, &target_x, &target_y))
	{
		if (is_terminal_char(game->map[target_y][target_x]))
			terminal_switch(game, target_x, target_y);
		else if (game->map[target_y][target_x] == 'm')
		{
			if (game->stage == 5)
			{
				printf("01001101 ");
				printf("01001001 ");
				printf("01000001 ");
				printf("01001111 ");
				printf("01010101\n");
			}
			else
				printf("MIAOU\n");
			game->moulinette_find = 1;
		}
		else
			toggle_door(game, target_x, target_y);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:17:02 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 07:58:46 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	player_touch_out(t_game *game, char out)
{
	double	new_pos;

	if (game->map[(int)game->player->y][(int)game->player->x] == out)
	{
		new_pos = game->player->x + 0.5;
		if (game->map[(int)game->player->y][(int)new_pos] == 's')
			return (1);
		new_pos = game->player->x - 0.5;
		if (game->map[(int)game->player->y][(int)new_pos] == 's')
			return (1);
		new_pos = game->player->y + 0.5;
		if (game->map[(int)new_pos][(int)game->player->x] == 's')
			return (1);
		new_pos = game->player->y - 0.5;
		if (game->map[(int)new_pos][(int)game->player->x] == 's')
			return (1);
	}
	return (0);
}

int	win_condition(t_game *game)
{
	char	win;

	if (game->stage % 2 == 0)
		win = '8';
	else
		win = '9';
	if (player_touch_out(game, win))
		return (1);
	else
		return (0);
}

int	loose_condition(t_game *game)
{
	char	loose;

	if (game->stage % 2 == 0)
		loose = '9';
	else
		loose = '8';
	if (player_touch_out(game, loose))
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:16:50 by hhervieu          #+#    #+#             */
/*   Updated: 2026/06/10 08:16:50 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	fill_doors(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '8' || game->map[y][x] == '9')
			{
				game->doors[i].x = x;
				game->doors[i].y = y;
				game->doors[i].state = DOOR_CLOSED;
				game->doors[i].offset = 0.0;
				game->doors[i].type = game->map[y][x];
				i++;
			}
			x++;
		}
		y++;
	}
}

void	toggle_door(t_game *game, int target_x, int target_y)
{
	t_door	*door;

	door = get_door_at(game, target_x, target_y);
	if (!door)
		return ;
	if ((int)game->player->y == target_y && (int)game->player->x == target_x)
		return ;
	if (door->state == DOOR_CLOSED || door->state == DOOR_CLOSING)
		door->state = DOOR_OPENING;
	else if (door->state == DOOR_OPEN || door->state == DOOR_OPENING)
		door->state = DOOR_CLOSING;
}

void	update_doors(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->doors[i].state == DOOR_OPENING)
		{
			game->doors[i].offset += 0.05;
			if (game->doors[i].offset >= 1.0)
			{
				game->doors[i].state = DOOR_OPEN;
				game->doors[i].offset = 1;
			}
		}
		if (game->doors[i].state == DOOR_CLOSING)
		{
			game->doors[i].offset -= 0.05;
			if (game->doors[i].offset <= 0.0)
			{
				game->doors[i].state = DOOR_CLOSED;
				game->doors[i].offset = 0;
			}
		}
		i++;
	}
}

t_door	*get_door_at(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (&game->doors[i]);
		i++;
	}
	return (NULL);
}

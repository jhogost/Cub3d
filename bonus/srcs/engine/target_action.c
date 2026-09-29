/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:07:14 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 17:34:38 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

static int	north_target(t_game *game, t_coord *player, int *x, int *y)
{
	if (is_interachar(game->map[(int)player->y][(int)player->x]))
	{
		if (player->y - floor(player->y) > 0.5)
		{
			*x = (int)player->x;
			*y = (int)player->y;
			return (1);
		}
	}
	if (is_interachar(game->map[(int)player->y - 1][(int)player->x]))
	{
		*x = (int)player->x;
		*y = (int)player->y - 1;
		return (1);
	}
	return (0);
}

static int	south_target(t_game *game, t_coord *player, int *x, int *y)
{
	if (is_interachar(game->map[(int)player->y][(int)player->x]))
	{
		if (player->y - floor(player->y) < 0.5)
		{
			*x = (int)player->x;
			*y = (int)player->y;
			return (1);
		}
	}
	if (is_interachar(game->map[(int)player->y + 1][(int)player->x]))
	{
		*x = (int)player->x;
		*y = (int)player->y + 1;
		return (1);
	}
	return (0);
}

static int	east_target(t_game *game, t_coord *player, int *x, int *y)
{
	if (is_interachar(game->map[(int)player->y][(int)player->x]))
	{
		if (player->x - floor(player->x) < 0.5)
		{
			*x = (int)player->x;
			*y = (int)player->y;
			return (1);
		}
	}
	if (is_interachar(game->map[(int)player->y][(int)player->x + 1]))
	{
		*x = (int)player->x + 1;
		*y = (int)player->y;
		return (1);
	}
	return (0);
}

static int	west_target(t_game *game, t_coord *player, int *x, int *y)
{
	if (is_interachar(game->map[(int)player->y][(int)player->x]))
	{
		if (player->x - floor(player->x) > 0.5)
		{
			*x = (int)player->x;
			*y = (int)player->y;
			return (1);
		}
	}
	if (is_interachar(game->map[(int)player->y][(int)player->x - 1]))
	{
		*x = (int)player->x - 1;
		*y = (int)player->y;
		return (1);
	}
	return (0);
}

int	get_target(t_game *game, t_coord *player, int *x, int *y)
{
	char	dir;

	dir = get_player_direction(player);
	if (dir == 'N')
		return (north_target(game, player, x, y));
	else if (dir == 'S')
		return (south_target(game, player, x, y));
	else if (dir == 'E')
		return (east_target(game, player, x, y));
	else
		return (west_target(game, player, x, y));
}

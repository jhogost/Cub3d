/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 10:54:41 by hhervieu          #+#    #+#             */
/*   Updated: 2026/06/15 16:31:11 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	lock_or_unlock_mouse(t_game *game)
{
	if (game->mouse_locked)
	{
		mlx_mouse_hide(game->mlx, game->win);
		center_and_hide_mouse(game);
		game->mouse_locked = 0;
	}
	else
	{
		mlx_mouse_show(game->mlx, game->win);
		game->mouse_locked = 1;
	}
}

void	init_mouse(t_game *game)
{
	game->mouse_x = WIN_WIDTH / 2;
	game->mouse_y = WIN_HEIGHT / 2;
}

void	center_and_hide_mouse(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

int	handle_mouse_move(int x, int y, t_game *game)
{
	int		diff_x;
	double	rotation_speed;

	(void)y;
	if (game->mouse_locked == 1)
		return (0);
	diff_x = x - (WIN_WIDTH / 2);
	rotation_speed = 0.001;
	if (diff_x == 0)
		return (0);
	else
		rotate_player(game->player, diff_x * rotation_speed);
	mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

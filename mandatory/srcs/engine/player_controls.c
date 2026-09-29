/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:54:14 by hhervieu          #+#    #+#             */
/*   Updated: 2026/05/25 16:54:14 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

void	move_player(t_game *game, double direction)
{
	double	next_x;
	double	next_y;
	double	speed;
	t_coord	*player;

	player = game->player;
	speed = direction * 0.12;
	next_x = player->x + player->ply_dir_x * speed;
	next_y = player->y + player->ply_dir_y * speed;
	if (can_walk(game->map, next_x, player->y))
		player->x = next_x;
	if (can_walk(game->map, player->x, next_y))
		player->y = next_y;
}

void	strafe_player(t_game *game, double direction)
{
	double	next_x;
	double	next_y;
	double	speed;
	t_coord	*player;

	player = game->player;
	speed = direction * 0.12;
	next_x = player->x - player->ply_dir_y * speed;
	next_y = player->y + player->ply_dir_x * speed;
	if (can_walk(game->map, next_x, player->y))
		player->x = next_x;
	if (can_walk(game->map, player->x, next_y))
		player->y = next_y;
}

void	rotate_player(t_coord *player, double angle)
{
	double	old_dir_x;

	old_dir_x = player->ply_dir_x;
	player->ply_dir_x = player->ply_dir_x * cos(angle)
		- player->ply_dir_y * sin(angle);
	player->ply_dir_y = old_dir_x * sin(angle)
		+ player->ply_dir_y * cos(angle);
	player->sensor_x = -player->ply_dir_y * FOV;
	player->sensor_y = player->ply_dir_x * FOV;
}

void	update_player(t_game *game)
{
	if (game->input[INPUT_FORWARD])
		move_player(game, 0.80);
	if (game->input[INPUT_BACKWARD])
		move_player(game, -0.80);
	if (game->input[INPUT_STRAFE_LEFT])
		strafe_player(game, -0.75);
	if (game->input[INPUT_STRAFE_RIGHT])
		strafe_player(game, 0.75);
	if (game->input[INPUT_TURN_LEFT])
		rotate_player(game->player, -0.047);
	if (game->input[INPUT_TURN_RIGHT])
		rotate_player(game->player, 0.047);
}

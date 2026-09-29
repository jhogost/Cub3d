/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:21:16 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/28 09:23:48 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, 0);
	else if (keycode == KEY_W)
		game->input[INPUT_FORWARD] = 1;
	else if (keycode == KEY_S)
		game->input[INPUT_BACKWARD] = 1;
	else if (keycode == KEY_A)
		game->input[INPUT_STRAFE_LEFT] = 1;
	else if (keycode == KEY_D)
		game->input[INPUT_STRAFE_RIGHT] = 1;
	else if (keycode == KEY_LEFT)
		game->input[INPUT_TURN_LEFT] = 1;
	else if (keycode == KEY_RIGHT)
		game->input[INPUT_TURN_RIGHT] = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input[INPUT_FORWARD] = 0;
	else if (keycode == KEY_S)
		game->input[INPUT_BACKWARD] = 0;
	else if (keycode == KEY_A)
		game->input[INPUT_STRAFE_LEFT] = 0;
	else if (keycode == KEY_D)
		game->input[INPUT_STRAFE_RIGHT] = 0;
	else if (keycode == KEY_LEFT)
		game->input[INPUT_TURN_LEFT] = 0;
	else if (keycode == KEY_RIGHT)
		game->input[INPUT_TURN_RIGHT] = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!is_ok_arg(argc, argv))
		return (1);
	init(argv[1], &game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0,
		(void *)handle_key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 1L << 1,
		(void *)handle_key_release, game);
	mlx_hook(game->win, EVENT_DESTROY, 0, (void *)exit_game, game);
	mlx_loop_hook(game->mlx, (void *)render_frame, game);
	mlx_loop(game->mlx);
	exit_game(game, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:21:16 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 15:52:15 by jbayet           ###   ########.fr       */
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
	else if (keycode == KEY_L)
		lock_or_unlock_mouse(game);
	else if (keycode == KEY_E)
		action_player(game);
	return (0);
}

static void	print_stage_message(int stage, char *msg, int door)
{
	if (stage == 3)
		printf("Stage %d ", stage + 1);
	else if (stage > 3)
		printf("Stage %d ", stage + 2);
	else
		printf("Stage %d ", stage);
	printf("%s in the door %d << ", msg, door);
	if (stage == 0)
		printf("%d\n", door);
	else if (stage == 1)
		printf("1%d\n", door);
	else if (stage == 2)
		printf("10%d\n", door);
	else if (stage == 3)
		printf("101%d\n", door);
	else if (stage == 4)
		printf("1010%d\n", door);
	else
		printf("10101%d\n", door);
}

int	game_loop(t_game *game)
{
	if (render_frame(game))
		return (0);
	update_doors(game);
	update_player(game);
	if (win_condition(game))
	{
		print_stage_message(game->stage, "passed", (game->stage + 1) % 2);
		free_stage(game);
		game->stage++;
		init_next_stage(game);
	}
	if (loose_condition(game))
	{
		print_stage_message(game->stage, "failed", game->stage % 2);
		printf("You've fallen into the black hole...\n");
		exit_game(game, 0);
	}
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
	mlx_hook(game->win, 6, 1L << 6,
		(void *)handle_mouse_move, game);
	mlx_hook(game->win, EVENT_DESTROY, 0, (void *)exit_game, game);
	center_and_hide_mouse(game);
	mlx_loop_hook(game->mlx, (void *)game_loop, game);
	mlx_loop(game->mlx);
	exit_game(game, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:24:15 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/09 19:09:33 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubddd.h"

static void	swap_sprite(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->sprite_count - 1)
	{
		j = i + 1;
		while (j < game->sprite_count)
		{
			if (game->sprites[i].dist < game->sprites[j].dist)
				swap_sprite(&game->sprites[i], &game->sprites[j]);
			j++;
		}
		i++;
	}
}

static void	get_distance_sprite(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		game->sprites[i].dist = (game->player->x - game->sprites[i].x)
			* (game->player->x - game->sprites[i].x)
			+ (game->player->y - game->sprites[i].y)
			* (game->player->y - game->sprites[i].y);
		i++;
	}
}

static t_img	*get_img_sprite(t_game *game, t_sprite *sprite)
{
	struct timeval	time;

	if (sprite->id == 'l')
		return (game->textures->lig);
	else if ((sprite->id == 't' || sprite->id == 'u' || sprite->id == 'v')
		&& sprite->status == 0)
		return (game->textures->tof);
	else if (sprite->id == 't' && sprite->status == 1)
		return (game->textures->ton);
	else if (sprite->id == 'u' && sprite->status == 1)
		return (game->textures->rto);
	else if (sprite->id == 'v' && sprite->status == 1)
		return (game->textures->rti);
	else if (sprite->id == 'm')
	{
		gettimeofday(&time, NULL);
		if (time.tv_sec % 3 == 0)
			return (game->textures->m_b);
		else
			return (game->textures->m_a);
	}
	else
		return (game->textures->lig);
}

void	draw_sprites(t_game *game)
{
	int		i;
	t_img	*img;

	get_distance_sprite(game);
	sort_sprites(game);
	i = 0;
	while (i < game->sprite_count)
	{
		img = get_img_sprite(game, &game->sprites[i]);
		draw_one_sprite(game, &game->sprites[i], img);
		i++;
	}
}

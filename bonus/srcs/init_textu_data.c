/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textu_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:17:18 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:17:58 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	init_textu_img_data_part1(t_textures *textures)
{
	textures->no->img_ptr = NULL;
	textures->no->addr = NULL;
	textures->so->img_ptr = NULL;
	textures->so->addr = NULL;
	textures->we->img_ptr = NULL;
	textures->we->addr = NULL;
	textures->ea->img_ptr = NULL;
	textures->ea->addr = NULL;
	textures->lo ->img_ptr = NULL;
	textures->lo->addr = NULL;
	textures->gr->img_ptr = NULL;
	textures->gr->addr = NULL;
	textures->bl->img_ptr = NULL;
	textures->bl->addr = NULL;
	textures->pu->img_ptr = NULL;
	textures->pu->addr = NULL;
	textures->re->img_ptr = NULL;
	textures->re->addr = NULL;
	textures->or->img_ptr = NULL;
	textures->or->addr = NULL;
	textures->ye->img_ptr = NULL;
	textures->ye->addr = NULL;
	textures->al->img_ptr = NULL;
	textures->al->addr = NULL;
}

void	init_textu_img_data_part2(t_textures *textures)
{
	textures->hud->img_ptr = NULL;
	textures->hud->addr = NULL;
	textures->lig->img_ptr = NULL;
	textures->lig->addr = NULL;
	textures->ton->img_ptr = NULL;
	textures->ton->addr = NULL;
	textures->tof->img_ptr = NULL;
	textures->tof->addr = NULL;
	textures->m_a->img_ptr = NULL;
	textures->m_a->addr = NULL;
	textures->m_b->img_ptr = NULL;
	textures->m_b->addr = NULL;
	textures->doo->img_ptr = NULL;
	textures->doo->addr = NULL;
	textures->doi->img_ptr = NULL;
	textures->doi->addr = NULL;
	textures->rti->img_ptr = NULL;
	textures->rti->addr = NULL;
	textures->rto->img_ptr = NULL;
	textures->rto->addr = NULL;
	textures->st->img_ptr = NULL;
	textures->st->addr = NULL;
}

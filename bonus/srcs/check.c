/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:40:09 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:15:32 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	is_ok_arg(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (write(2, "Error\nMap name missing\n", 23), 0);
	else if (argc > 2)
		return (write(2, "Error\nToo many arguments\n", 25), 0);
	else
	{
		if (ft_strlen(argv[1]) < 4)
			return (write(2, "Error\nIs not a .cub file\n", 25), 0);
		if (argv[1][ft_strlen(argv[1]) - 1] != 'b'
		|| argv[1][ft_strlen(argv[1]) - 2] != 'u'
		|| argv[1][ft_strlen(argv[1]) - 3] != 'c'
		|| argv[1][ft_strlen(argv[1]) - 4] != '.')
			return (write(2, "Error\nIs not a .cub file\n", 25), 0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nOpen");
		return (0);
	}
	close(fd);
	return (1);
}

int	missing_info(t_game *game)
{
	if (!game->textures->no || !game->textures->so || !game->textures->we
		|| !game->textures->ea || !game->textures->lo || !game->textures->gr
		|| !game->textures->bl || !game->textures->pu || !game->textures->re
		|| !game->textures->or || !game->textures->ye || !game->textures->al
		|| !game->textures->st
		|| !game->textures->lig || !game->textures->hud || !game->textures->ton
		|| !game->textures->tof || !game->textures->rti || !game->textures->rto
		|| !game->textures->m_a || !game->textures->m_b
		|| !game->textures->doo || !game->textures->doi)
		return (1);
	if (!game->color->ceiling || !game->color->floor)
		return (1);
	if (game->color->ceiling->red == -1 || game->color->ceiling->green == -1
		|| game->color->ceiling->blue == -1)
		return (1);
	if (game->color->floor->red == -1 || game->color->floor->green == -1
		|| game->color->floor->blue == -1)
		return (1);
	return (0);
}

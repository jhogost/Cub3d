/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:40:09 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/21 12:55:02 by jbayet           ###   ########.fr       */
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
	if (!game->textures->no || !game->textures->so
		|| !game->textures->we || !game->textures->ea)
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

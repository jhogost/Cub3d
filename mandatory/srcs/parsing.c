/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:33:33 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/27 18:21:15 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	parsing_textures(char *line, t_game *game, t_img *texture)
{
	int	i;
	int	xy;

	xy = TEXTURE_SIZE;
	i = 2;
	while (line[i] == ' ')
		i++;
	if (texture->img_ptr)
		return (write(2, "Error\nTexture already applied\n", 30), 1);
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx, &line[i], &xy, &xy);
	if (!texture->img_ptr)
	{
		write(2, "Error\nFailed to load textures: ", 31);
		write(2, &line[i], ft_strlen(&line[i]));
		write(2, "\n", 1);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (write(2, "Error\nmlx_get_data_addr failed\n", 31), 1);
	return (0);
}

int	parsing_pixel(char *line, t_pixel *color, int j, unsigned int step)
{
	char	*clr;
	int		nb_tmp;

	if (color->blue != -1)
		return (write(2, "Error\nColor already applied\n", 28), 1);
	if (step > 3)
		return (write(2, "Error\nIncorrect color info\n", 27), 1);
	if ((step == 1 || step == 2) && !line[j])
		return (write(2, "Error\nIncorrect color info\n", 27), 1);
	if (step == 3 && line[j])
		return (write(2, "Error\nIncorrect color info\n", 27), 1);
	clr = ft_substr(line, 0, j);
	if (ft_strlen(clr) > 4 || !is_num_string(clr))
		return (free(clr), write(2, "Error\nIncorrect color info\n", 27), 1);
	nb_tmp = ft_atoi(clr);
	if (nb_tmp < 0 || nb_tmp > 255)
		return (free(clr), write(2, "Error\nIncorrect color info\n", 27), 1);
	if (step == 1)
		color->red = nb_tmp;
	else if (step == 2)
		color->green = nb_tmp;
	else if (step == 3)
		color->blue = nb_tmp;
	return (free(clr), 0);
}

int	parsing_color(char *line, t_pixel *color)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	step;

	step = 1;
	i = 1;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		j = 0;
		while (line[i + j] && line[i + j] != ',')
			j++;
		if (parsing_pixel(&line[i], color, j, step))
			return (1);
		step++;
		i += j;
		if (line[i])
			i++;
	}
	return (0);
}

int	parsing_line(char *line, t_game *game)
{
	if (is_empty_line(line))
		return (0);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->no));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->so));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->we));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parsing_textures(line, game, game->textures->ea));
	else if (line[0] == 'F' && line[1] == ' ')
		return (parsing_color(line, game->color->floor));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parsing_color(line, game->color->ceiling));
	else if (is_map_line(line))
		return (2);
	else
		return (write(2, "Error\nIncorrect color and texture info\n", 39), 1);
}

int	parsing_textu_color(char *filename, t_game *game)
{
	int		status;
	int		fd;
	char	*line;

	status = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nOpen"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (!status)
			status = parsing_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->color->ceiling_pixel = create_rgb(game->color->ceiling);
	game->color->floor_pixel = create_rgb(game->color->floor);
	return (close(fd), status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:23:05 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/19 11:25:11 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

static char	*read_to_stock(int fd, char *stock)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (perror("Error\nGet next line fonction"), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stock, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			if (stock)
				free(stock);
			return (NULL);
		}
		buf[bytes] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

static char	*extract_line(char *stock)
{
	size_t	i;

	if (!stock || stock[0] == '\0')
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	return (ft_substr(stock, 0, i));
}

static char	*clean_stock(char *stock)
{
	size_t	i;
	char	*newstock;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	newstock = ft_strdup(stock + i + 1);
	free(stock);
	return (newstock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_to_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = extract_line(stock);
	stock = clean_stock(stock);
	return (line);
}

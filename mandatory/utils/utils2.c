/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:30:49 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/19 11:25:26 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

static int	n_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	ln;

	size = n_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (perror("Error\nItoa fonction"), NULL);
	ln = (long)n;
	if (ln < 0)
	{
		result[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
		result[0] = '0';
	result[size] = '\0';
	while (ln != 0)
	{
		result[size - 1] = (ln % 10) + '0';
		ln /= 10;
		size--;
	}
	return (result);
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == '6')
		return ;
	else if (map[y][x] == 'P')
		return ;
	else if (map[y][x] == '2' || map[y][x] == '3')
		return ;
	else
	{
		if (map[y][x] == '0')
			map[y][x] = '2';
		if (map[y][x] == 'C')
			map[y][x] = '3';
		flood_fill(map, x + 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y - 1);
	}
	return ;
}

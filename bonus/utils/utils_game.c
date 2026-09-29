/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:54:29 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 18:23:56 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	is_walkable(char c)
{
	if (c == '0' || c == 'l' || c == 'm' || c == 't' || c == 'u'
		|| c == 'v' || is_player(c) || c == '8' || c == '9')
		return (1);
	else
		return (0);
}

int	is_sprite_char(char c)
{
	if (c == 'l' || c == 'm' || c == 't' || c == 'u' || c == 'v')
		return (1);
	else
		return (0);
}

int	is_wall_char(char c)
{
	if (c == '1' || c == '2' || c == '3' || c == '8' || c == '9'
		|| c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e'
		|| c == 'f' || c == 'g' || c == 'h' || c == 's')
		return (1);
	else
		return (0);
}

int	is_map_char(char c)
{
	if (c == ' ' || is_wall_char(c) || is_walkable(c))
		return (1);
	else
		return (0);
}

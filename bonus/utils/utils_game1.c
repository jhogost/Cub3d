/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:30:28 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/11 17:29:42 by jbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubddd.h"

int	is_door_char(char c)
{
	if (c == '8' || c == '9')
		return (1);
	else
		return (0);
}

int	is_terminal_char(char c)
{
	if (c == 't' || c == 'u' || c == 'v')
		return (1);
	else
		return (0);
}

int	is_interachar(char c)
{
	if (is_door_char(c) || is_terminal_char(c) || c == 'm')
		return (1);
	else
		return (0);
}

int	is_door_closed(t_door *doors, char c)
{
	if (doors[0].type == c && (doors[0].state == DOOR_CLOSED
			|| doors[0].state == DOOR_OPENING
			|| doors[0].state == DOOR_CLOSING))
		return (1);
	if (doors[1].type == c && (doors[1].state == DOOR_CLOSED
			|| doors[1].state == DOOR_OPENING
			|| doors[1].state == DOOR_CLOSING))
		return (1);
	return (0);
}

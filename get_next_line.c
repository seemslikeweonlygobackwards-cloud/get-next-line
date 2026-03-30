/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:15:15 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/25 19:52:24 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	static int	i;

	i = 0;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read (fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n'))
		return (buffer);
}

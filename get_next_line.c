/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:15:15 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/30 21:05:02 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_funciton(char *stash, char *buffer, int fd)
{
	int		byte;
	char	*temp;

	byte = read (fd, buffer, BUFFER_SIZE);
	if (byte < 0)
		return (NULL);
	while (byte && !ft_strchr(buffer, '\n'))
	{
		temp = stash;
		stash = strjoin(stash, buffer);
		free(temp);
		byte = read (fd, buffer, BUFFER_SIZE);
	}
	temp = stash;
	stash = strjoin(stash, buffer);
	free(temp);
	return (stash);
}

char	*extraction ()
{
	
}
char	*stash_update()
{
	
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	int			byte;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = read (fd, buffer, BUFFER_SIZE);
	if (byte < 0)
		return (free(buffer), NULL);
	while (*buffer)
	{
		*stash = ft_strjoin(stash, buffer);
		if (*buffer == "\n")
			return (ft_strdup(buffer));
	}
}

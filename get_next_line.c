/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:15:15 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/01 20:02:47 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_function(char *stash, int fd)
{
	int		byte;
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = read(fd, buffer, BUFFER_SIZE);
	while (byte > 0)
	{
		buffer[byte] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
		byte = read(fd, buffer, BUFFER_SIZE);
	}
	if (byte < 0)
		return (free(buffer), free(stash), NULL);
	return (free(buffer), stash);
}

char	*extraction(char *stash)
{
	int	i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (ft_strdup(stash, i + 1));
		i++;
	}
	return (ft_strdup(stash, i));
}

char	*stash_update(char *stash)
{
	int		i;
	int		len;
	char	*temp;
	char	*new_stash;

	if (!stash)
		return (NULL);
	len = ft_strlen(stash);
	temp = stash;
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			new_stash = ft_strdup(stash + i + 1, len - i - 1);
			free(temp);
			return (new_stash);
		}
		i++;
	}
	free(temp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_function(stash, fd);
	if (!stash)
		return (NULL);
	temp = extraction(stash);
	if (!temp)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = stash_update(stash);
	return (temp);
}

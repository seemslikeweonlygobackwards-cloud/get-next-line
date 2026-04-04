/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:43:46 by monika            #+#    #+#             */
/*   Updated: 2026/04/04 14:14:30 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[OPEN_MAX];
	char		*temp;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_function(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	temp = extraction(stash[fd]);
	if (!temp)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = stash_update(stash[fd]);
	return (temp);
}

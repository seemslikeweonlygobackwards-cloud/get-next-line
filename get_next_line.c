/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:15:15 by mavanesy          #+#    #+#             */
/*   Updated: 2026/04/01 16:06:41 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_function(char *stash, int fd)
{
	int		byte;
	char	*temp;
	char	*buffer;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = read (fd, buffer, BUFFER_SIZE);
	if (byte < 0)
		return (free(buffer), free(stash), NULL);
	buffer[byte] = '\0';
	while (byte && !ft_strchr(stash, '\n'))
	{
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		byte = read (fd, buffer, BUFFER_SIZE);
	}
	temp = stash;
	stash = ft_strjoin(stash, buffer);
	free(temp);
	return (free(buffer), stash);
}

char	*extraction (char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] =='\n')
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

	i = 0;
	if (!stash)
		return (NULL);
	len = ft_strlen(stash);
	temp = stash;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (free(temp), ft_strdup(stash + i + 1, len - i - 1));
		i++;
	}
	return (free(temp), NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = read_function(stash, fd);
	temp = extraction(stash);
	stash = stash_update(stash); 
	return (temp);
}

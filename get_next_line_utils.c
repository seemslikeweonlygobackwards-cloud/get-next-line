/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavanesy <mavanesy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:15:11 by mavanesy          #+#    #+#             */
/*   Updated: 2026/03/25 19:39:15 by mavanesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	n;

	n = 0;
	while (c[n] != 0)
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len;
	int		len1;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	len1 = ft_strlen(s1);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < len1)
			new[i] = s1[i];
		if (i >= len1)
		{
			new[i] = s2[i - len1];
		}
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	len;
	size_t	i;

	len = ft_strlen (s);
	c = malloc (len + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		c[i] = s[i];
		i++;
	}
	return (c);
}

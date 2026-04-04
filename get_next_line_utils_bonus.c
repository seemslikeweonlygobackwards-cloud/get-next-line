/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:46:27 by monika            #+#    #+#             */
/*   Updated: 2026/04/04 14:14:33 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *c)
{
	int	n;

	n = 0;
	if (!c)
		return (0);
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

	if (!s1)
		return (ft_strdup(s2, ft_strlen(s2)));
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
		else
			new[i] = s2[i - len1];
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
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

char	*ft_strdup(const char *s, int len)
{
	char	*c;
	int		i;

	c = malloc (len + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (i < len)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

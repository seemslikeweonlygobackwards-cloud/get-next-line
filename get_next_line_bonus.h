/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monika <monika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:46:21 by monika            #+#    #+#             */
/*   Updated: 2026/04/04 13:52:18 by monika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#ifndef OPEN_MAX
#   define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line_bonus(int fd);
int		ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s, int len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

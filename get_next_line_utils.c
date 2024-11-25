/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:42:33 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/24 15:21:18 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t		i;
	size_t		len_s;

	i = 0;
	len_s = ft_strlen(s1);
	str = (char *)malloc ((len_s + 1));
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strjoin(char *s1, char  *s2)
{
	size_t		i;
	size_t		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (free(s1),s1 = NULL,NULL);
	j = 0;
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	// if (s1)
	// {
	// }
		free(s1);
		s1 = NULL;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	len_s;

	if (!s || len < 0)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
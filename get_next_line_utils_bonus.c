/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:19 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/28 09:48:21 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;
	size_t		len_s;

	if (!s1)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i])
		str[j++] = s1[i++];
	str[j] = '\0';
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	size_t		i;
	size_t		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		return (NULL);
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

char	*copy_s(char *s, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	i++;
	s[i - 1] = '\n';
	s[i] = '\0';
	return (s);
}

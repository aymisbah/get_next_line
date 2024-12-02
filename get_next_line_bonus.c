/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:16 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/29 16:21:32 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*add_c(char *c)
{
	char	*str;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	while (c[i])
	{
		if (c[i] == '\n')
			break ;
		i++;
	}
	i++;
	str = ft_substr(c, i, ft_strlen(c) - i);
	return (str);
}

static char	*get_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (ft_strdup(str));
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	copy_s(s, str);
	return (s);
}

static char	*read_file(int fd, char *buffer, char *c)
{
	ssize_t	r;

	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free(buffer), buffer = NULL, NULL);
		buffer[r] = 0;
		c = ft_strjoin(c, buffer);
		if (new_line(buffer) || r == 0)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (c);
}

char	*get_next_line(int fd)
{
	static char	*c[OPEN_MAX];
	char		*buffer;
	char		*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd
		|| BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = read_file(fd, buffer, c[fd]);
	if (!str)
		return (free(c[fd]), c[fd] = NULL, NULL);
	if (!*str)
		return (free(str), str = NULL, NULL);
	c[fd] = add_c(str);
	s = get_line(str);
	free(str);
	str = NULL;
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:42:28 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/24 15:26:31 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int new_line(char *s)
{
   int i = 0;

   while(s[i] && i < BUFFER_SIZE)
   {
      if (s[i] == '\n')
      {
			// free(s);
			// s = NULL; 
			return (1);
		}
      i++;
   }
   return(0);
}
static char *add_c(char *c)
{
	int	i = 0;
	char *str;
	if (!c)
		return (NULL);
	while(c[i]) 
	{
		if (c[i] == '\n' )
			break;
		i++;
	}
	i++;
	str = ft_substr(c,i,ft_strlen(c) - i);
	return(str);
}
char *get_line(char *str)
{
	int	i = 0;
	char *s ;
	if (!str)
		return (NULL);
	while(str[i])
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	if (str[i] == '\0')
		return(ft_strdup(str));
	s = malloc (i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	i++;
	s[i - 1] = '\n';
	s[i] = '\0';
	// free(str);
	return(s);
}
char *read_file(int fd,char *buffer,char *c)
{
	ssize_t	r;
	while(1)
	{
		r = read(fd,buffer,BUFFER_SIZE);
		buffer[r] = 0;
		if (r == -1)
			return (free(buffer),buffer = NULL,NULL);
		if (r == 0)
		{
			break;
		}
		c = ft_strjoin(c, buffer);
			if (new_line(buffer))
				break;
	}
	free(buffer);
	buffer = NULL;
	return (c);
}
char *get_next_line(int fd)
{
   static char	*c;
   char	*buffer;
	char	*str;
	char *s;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	str = read_file(fd, buffer, c);
	if (!str)
		return(NULL);
	if (!*str)
		return(free(str), NULL);
	s = get_line(str);
	c = add_c(str);
	free(str);
	str = NULL;
	return(s);
}
// void gg()
// {
// 	system("leaks a.out");
// }


// int main()
// {
// 	atexit(gg);
// 	int fd = open("test.txt",O_RDWR,777);
// 	char *s ;
// 	int  i = 0;
// 	while (i <  2)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s",s);
// 		if (s)
// 		 	free(s);
// 		++i;
// 	}
	
	
// }


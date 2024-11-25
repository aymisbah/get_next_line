/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:16 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/25 17:30:49 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


static int new_line(char *s)
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
static char *get_line(char *str)
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
	return(s);
}
static char *read_file(int fd,char *buffer,char *c)
{
	ssize_t	r;
	while(1)
	{
		r = read(fd,buffer,BUFFER_SIZE);
		buffer[r] = 0;
		if (r == -1)
			return (free(buffer),buffer = NULL,NULL);
		if (r == 0)
			break;
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
   static char	*c[OPEN_MAX];
   char	*buffer;
	char	*str;
	char *s;
	if (fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX || fd < 0)
      return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	str = read_file(fd, buffer, c[fd]);
	if (!str)
		return(NULL);
	if (!*str)
		return(free(str), NULL);
	s = get_line(str);
	c[fd] = add_c(str);
	free(str);
	str = NULL;
	return(s);
}
void gg()
{
	system("leaks a.out");
}


int main()
{
	// atexit(gg);
	int fd = open("test.txt",O_RDWR,777);
	// int fd1 = open("test1.txt",O_RDWR,777);
	// int fd2 = open("test2.txt",O_RDWR,777);
	// int fd3 = open("test3.txt",O_RDWR,777);
	char *s ;
	// char *s1 ;
	// char *s2 ;
	// char *s3 ;
	int  i = 0;
	while (i <  1)
	{
		s = get_next_line(fd);
		printf("%s",s);
		// s1 = get_next_line(fd1);
		// printf("%s",s1);
		// s2 = get_next_line(fd2);
		// printf("%s",s2);
		// s3 = get_next_line(fd3);
		// printf("%s",s3);
		if (s)
		 	free(s);
		// if (s1)
		//  	free(s1);
		// if (s2)
		//  	free(s2);
		// if (s3)
		//  	free(s3);
		++i;
	}
	
	
}


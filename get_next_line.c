/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:42:28 by aymisbah          #+#    #+#             */
/*   Updated: 2024/11/22 16:54:04 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int new_line(char *s)
{
   int i = 0;
   int rs = 0;

   while(s[i] && i < BUFFER_SIZE)
   {
      if (s[i] == '\n')
         return (1);
      i++;
   }
	// i++;
   return(0);
}



// // char *get_next_line(int fd)
// // {
// //    // static char *cur;
// //    char buffer[BUFFER_SIZE + 1];
// //    // char *str;
// //    char *s;
// //    int i  = 0;
// //    // int j  = 0;
   
// //    while(1)
// //    {
// //       i = read(fd, buffer,BUFFER_SIZE);
// //       buffer[i] = '\0';
// //       s = malloc(20);
// //       // printf("--%s",buffer);
// //       strcpy(s,buffer);
      
// //       // strcat(s,buffer);
// //       // printf("%s",s);
// //       // while(new_line(s) == 0)
// //       // {
// //       // }
// //       if(new_line(s))
// //          break;
// //       // return(strdup(s));
// //    }
// //    return(s);
// // }
char *add_c(char *c)
{
	int	i = 0;
	if (!c)
		return (NULL);
	while(c[i]) //  && (c[i] != '\n' || c[i] != '\0')
	{
		if (c[i] == '\n' )
			break;
		i++;
	}
	i++;
	printf(">>%d", i);
	c = ft_substr(c,i,ft_strlen(c) - i);
	c[i] = '\0';
	return(c);
}
char *get_line(char *str)
{
	int	i = 0;
	char *s;
	while(str[i]) //  && (str[i] != '\n' || str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	s = malloc (i + 1);
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	i++;
	// printf("--%d\n",i);
	s[i - 1] = '\n';
	s[i] = '\0';
	return(s);
}
char *read_file(int fd,char *buffer,char *c)
{
	ssize_t	r;
	while(1)
	{
		r = read(fd,buffer,BUFFER_SIZE);
		if (r == -1)
			return(NULL);
		if (r == 0)
			break;					
		c = ft_strjoin(c,buffer);
		if (new_line(buffer))
			break;
	}
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
	str = read_file(fd,buffer,c);
	if (!str)
		return (NULL);
	c = add_c(str);
	s = get_line(str);
	return(s);
}


int main()
{
	int fd = open("test.txt",O_RDWR,777);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
}


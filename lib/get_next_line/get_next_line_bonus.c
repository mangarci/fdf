/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:58:19 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/08 17:51:40 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *s)
{
	unsigned char		*str;
	size_t				i;

	str = (unsigned char *)s;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_return(int len, char **line)
{
	if (len < 0)
		return (-1);
	*line = ft_strdup_gnl("");
	return (0);
}

char	*ft_get_line(char *s, char **line, int *len)
{
	char	*aux;
	int		pos;

	pos = 0;
	while (s[pos] != '\n' && s[pos] != '\0')
		pos++;
	if (s[pos] == '\n')
	{
		*line = ft_substr_gnl(s, 0, pos);
		aux = ft_strdup_gnl(s + (pos + 1));
		free(s);
		s = aux;
		if (s[0] == '\0')
			s = ft_del_gnl(s);
		*len = 1;
	}
	else
	{
		*line = ft_strdup_gnl(s);
		free(s);
		s = NULL;
		*len = 0;
	}
	return (s);
}

void	file_error(int fd, char **line)
{
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			len;
	char		buff[BUFF_SIZE + 1];
	char		*aux;

	file_error(fd, line);
	len = read(fd, buff, BUFF_SIZE);
	while (len > 0)
	{
		buff[len] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup_gnl(buff);
		else
		{
			aux = ft_strjoin_gnl(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr_gnl(s[fd], '\n'))
			break ;
		len = read(fd, buff, BUFF_SIZE);
	}
	if ((len < 0) || (len == 0 && s[fd] == '\0'))
		return (ft_return(len, line));
	s[fd] = ft_get_line(s[fd], line, &len);
	return (len);
}

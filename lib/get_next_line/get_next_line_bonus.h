/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:36:02 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/08 17:42:30 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup_gnl(char *s1);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_substr_gnl(const char *s, unsigned int start, size_t len);
void		*ft_del_gnl(char *s);
char		*ft_get_line(char *s, char **line, int *len);
size_t		ft_strlen(const char *s);
#endif

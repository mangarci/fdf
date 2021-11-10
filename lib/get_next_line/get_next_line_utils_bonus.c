/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:11:25 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/08 17:43:18 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup_gnl(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dst)
		return (NULL);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (NULL);
	if (start < j)
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

void	*ft_del_gnl(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)s;
	while (aux[i])
	{
		if (aux[i] == c)
			return (&aux[i]);
		i++;
	}
	if (aux[i] == '\0' && c == '\0')
		return (&aux[i]);
	return (NULL);
}

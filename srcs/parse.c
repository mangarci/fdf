/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:32:51 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 21:43:27 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		show_error("Map could't be opened");
	return (fd);
}

int	*get_wh(char *filename)
{
	int		*wh;
	int		fd;
	char	*line;
	char	**buffer;

	wh = malloc(sizeof(int) * 2);
	wh[1] = 0;
	fd = open_map(filename);
	while (get_next_line(fd, &line))
	{
		buffer = ft_split(line, ' ');
		wh[0] = array_length(buffer);
		wh[1]++;
		free(line);
		double_free(buffer);
	}
	free(line);
	close(fd);
	return (wh);
}

void	fill(char *line, int *map_line)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
	{
		map_line[i] = ft_atoi(buffer[i]);
		i++;
	}
	free(buffer);
}

t_map	parse_map(char *filename)
{
	t_map	map;
	int		i;
	int		*wh;

	i = 0;
	wh = get_wh(filename);
	map.width = wh[0];
	map.height = wh[1];
	free(wh);
	map.fd = open_map(filename);
	map.map = (int **)malloc(sizeof(int *) * map.height);
	while (i < map.height)
	{
		map.map[i] = (int *)malloc(sizeof(int) * map.width);
		i++;
	}
	i = 0;
	while ((get_next_line(map.fd, &map.line)) > 0)
	{
		fill(map.line, map.map[i++]);
		free(map.line);
	}
	close(map.fd);
	free(map.line);
	return (map);
}

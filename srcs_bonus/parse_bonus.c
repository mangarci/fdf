/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:32:51 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 19:08:37 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

int open_map(char *map_name)
{
    int fd;

    fd = open(map_name, O_RDONLY, 0);
    if (fd <= 0)
        show_error("Map could't be opened");
    return (fd);
}

int get_height(char *filename)
{
    int height;
    int fd;
    char    *line;

    height = 0;
    fd = open_map(filename);
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    free(line);
    return (height);
}

int get_width(char *filename)
{
    int width;
    int fd;
    char    *line;
    char **buffer;
    
    fd = open_map(filename);
    get_next_line(fd, &line);
    buffer = ft_split(line, ' ');
    width = array_length(buffer);
    free(line);
    free(buffer);
    close(fd);
    return (width);
}

void    fill(char *line, int *map_line)
{
    char    **buffer;
    int i;
    
    i = 0;
    buffer = ft_split(line, ' ');
    while (buffer[i])
    {
        map_line[i] = ft_atoi(buffer[i]);
        i++;
    }
    free(buffer);
}

t_map   parse_map(char *filename)
{
    t_map   map;
    int i;

    i = 0;
    map.width = get_width(filename);
    map.height = get_height(filename);
    map.fd = open_map(filename);
    map.map = (int **)malloc(sizeof(int *) * map.height);
    while (i < map.height)
    {
        map.map[i] = (int *)malloc(sizeof(int) * map.width);
        i++;
    }
    i = 0;
    while (get_next_line(map.fd, &map.line) > 0)
    {
        fill(map.line, map.map[i++]);
        free(map.line);
    }
    close(map.fd);
    free(map.line);
    return (map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:14:24 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/10 20:22:03 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int set_color(int x, int y, t_map map, t_range r)
{
    int z;
    float   i;
    
    z = map.map[y][x];
    i = (float)r.range / 6;
    if (z <= r.min + i)
        return (0x0000ff);
    else if (z <= (r.min + 2 * i))
        return (0xff00ff);
    else if (z <= (r.min + 3 * i))
        return (0xffffff);
    else if (z <= (r.min + 4 * i))
        return (0x00ff00);
    else if (z <= (r.min + 5 * i))
        return (0xff0000);
    else if (z <= (r.min + 6 * i))
        return (0xffff00);
    return (0);
}

void    mine_mlx_pixel_put(t_fdf *data, int x, int y)
{
    char    *dst;
    
    if (x >= SIZE_X || x < 0 || y >= SIZE_Y || y < 0)
        return ;
    dst = data->mlx.img.data + (y * data->mlx.img.size_line + x * (data->mlx.img.bbp / 8));
}

void    display_img(t_fdf *data)
{
    int y;
    int x;

    y = 0;
    while (y < data->map.width)
    {
        data->mlx.color = set_color(x, y, data->map, data->map.range);
        if (x < data->map.width - 1)
            plotline(x, y, x + 1, y, data);
        if (y < data->map.height - 1)
            plotline(x, y, x, y + 1, data);
        x++;
    }
    y++;
    mlx_put_image_to_window(data->mlx.ptr, data->mlx.window, data->mlx.img.ptr, 0 ,0);
}
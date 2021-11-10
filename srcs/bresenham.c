/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:39:22 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/10 20:30:45 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(int *x, int *y, int z, double angle)
{
    int pre_x;
    int pre_y;
    
    pre_x = *x;
    pre_y = *y;
    *x = (pre_x - pre_y) * cos(angle);
    *y = (pre_x + pre_y) * sin(angle) - z;
}

void    lowplotline(int x0, int y0, int x1, int y1, t_fdf *data)
{
    int dx;
    int dy;
    int yi;
    int d;
    int y;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if(dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    d = (2 * dy) - dx;
    y = y0;
    while (x0 < x1)
    {
        mine_mlx_pixel_put(data, x0, y);
        if (d > 0)
        {
            y = y + yi;
            d = d + (2 * (dy - dx));
        }
        else
            d = d + 2 * dy;
        x0++;
    }
}

void    highplotline(int x0, int y0, int x1, int y1, t_fdf *data)
{
    int dx;
    int dy;
    int xi;
    int d;
    int x;

    dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    d = (2 * dx) - dy;
    x = x0;
    while (y0 < y1)
    {
        mine_mlx_pixel_put(data, x, y0);
        if (d > 0)
        {
            x = x + xi;
            d = d + (2 * (dx - dy));
        }
        else
            d = d + 2 * dx;
        y0++;
    }
}

void    plotline(int x0, int y0, int x1, int y1, t_fdf *data)
{
    int z0;
    int z1;

    z0 = data->map.map[y0][x0];
    z1 = data->map.map[y1][x1];
    x0 *= data->cam.zoom;
    x1 *= data->cam.zoom;
    y0 *= data->cam.zoom;
    y1 *= data->cam.zoom;
    z0 *= data->cam.zoom / 2;
    z1 *= data->cam.zoom / 2;
    isometric(&x0, &y0, z0, data->cam.perspective_angle);
    isometric(&x1, &y1, z1, data->cam.perspective_angle);
    x0 += data->cam.pos_x;
    x1 += data->cam.pos_x;
    y0 += data->cam.pos_y;
    y1 += data->cam.pos_y;
    if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x0 > x1)
            lowplotline(x1, y1, x0, y0, data);
        else
            lowplotline(x0, y0, x1, y1, data);
    }
    else
    {
        if (y0 > y1)
            highplotline(x1, y1, x0, y0, data);
        else
            highplotline(x0, y0, x1, y1, data);
    }
}
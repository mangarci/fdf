/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:52:05 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 19:27:54 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

int zoom(int size)
{
    if (size <= 20)
        return (ZOOM);
    else if (size <= 50)
        return (ZOOM/2);
    else if (size < 150)
        return (ZOOM/4);
    else
        return (1);
}

t_cam   init_cam(t_fdf *data)
{
    t_cam   cam;
    
    data->map.range = range(data);
    cam.angle = 0.1;
    cam.perspective_angle = 0.53;
    cam.isometric = 1;
    cam.plane = 0;
    cam.oblique = 0;
    cam.zoom = zoom(data->map.width);
    cam.pos_x = SIZE_X / 3 + 100;
    cam.pos_y = SIZE_Y / 2;
    cam.rotate[0] = 0;
    cam.rotate[1] = 0;
    cam.rotate[2] = 0;
    return (cam);
}

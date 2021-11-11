/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_settings_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:08:58 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 21:16:41 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	perform_zoom(t_point *p0, t_point *p1, int z[2], t_fdf *data)
{
	p0->x *= data->cam.zoom;
	p0->y *= data->cam.zoom;
	p1->x *= data->cam.zoom;
	p1->y *= data->cam.zoom;
	z[0] *= data->cam.zoom / 2;
	z[1] *= data->cam.zoom / 2;
}

void	perform_position(t_point *p0, t_point *p1, t_fdf *data)
{
	p0->x += data->cam.pos_x;
	p0->y += data->cam.pos_y;
	p1->x += data->cam.pos_x;
	p1->y += data->cam.pos_y;
}

void	hooks_perspective(t_fdf *data, int keycode)
{
	if (keycode == K_I)
	{
		data->cam.isometric = 1;
		data->cam.plane = 0;
		data->cam.oblique = 0;
		data->cam.perspective_angle = 0.53;
	}
	if (keycode == K_P)
	{
		data->cam.plane = 1;
		data->cam.isometric = 0;
		data->cam.oblique = 0;
	}
	if (keycode == K_O)
	{
		data->cam.plane = 0;
		data->cam.isometric = 0;
		data->cam.oblique = 1;
		data->cam.perspective_angle = 0.2;
	}
}
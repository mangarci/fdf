/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:24:06 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/12 17:28:36 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	x_rotation(int *y, int *z, double angle)
{
	int	pre_y;
	int	pre_z;

	pre_y = *y;
	pre_z = *z;
	*y = pre_y * cos(angle) + pre_z * sin(angle);
	*z = -pre_y * sin(angle) + pre_z * cos(angle);
}

void	y_rotation(int *x, int *z, double angle)
{
	int	pre_x;
	int	pre_z;

	pre_x = *x;
	pre_z = *z;
	*x = pre_x * cos(angle) + pre_z * sin(angle);
	*z = -pre_x * sin(angle) + pre_z * cos(angle);
}

void	z_rotation(int *x, int *y, double angle)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(angle) - pre_y * sin(angle);
	*y = pre_x * sin(angle) + pre_y * cos(angle);
}

void	rotate(int *x, int *y, int *z, t_fdf *data)
{
	if (data->cam.rotate[0])
		x_rotation(y, z, data->cam.angle);
	if (data->cam.rotate[1])
		y_rotation(x, z, data->cam.angle);
	if (data->cam.rotate[2])
		z_rotation(x, y, data->cam.angle);
}

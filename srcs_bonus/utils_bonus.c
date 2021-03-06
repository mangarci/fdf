/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:28:00 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/12 17:20:37 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

int	double_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

t_range	range(t_fdf *data)
{
	int		x;
	int		y;
	t_range	r;

	y = 0;
	r.max = __INT_MAX__ * -1;
	r.min = __INT_MAX__;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map[y][x] < r.min)
				r.min = data->map.map[y][x];
			if (data->map.map[y][x] > r.max)
				r.max = data->map.map[y][x];
			x++;
		}
		y++;
	}
	r.range = abs(r.max - r.min);
	return (r);
}

int	key_action(int keycode, t_fdf *data)
{
	if (keycode == K_ESC)
		close_window(&data->mlx);
	if (keycode == K_W)
		data->cam.pos_y -= 20;
	if (keycode == K_A)
		data->cam.pos_x -= 20;
	if (keycode == K_D)
		data->cam.pos_x += 20;
	if (keycode == K_S)
		data->cam.pos_y += 20;
	hooks_perspective(data, keycode);
	cam_mov(keycode, data);
	new_image(data);
	return (0);
}

int	close_x(t_mlx *mlx)
{
	close_window(mlx);
	return (0);
}

void	hook_loop(t_fdf *data)
{
	mlx_key_hook(data->mlx.window, key_action, data);
	mlx_hook(data->mlx.window, 17, (1L << 17), close_x, &data->mlx);
	mlx_mouse_hook(data->mlx.window, zoom_bonus, data);
	mlx_loop(data->mlx.ptr);
}

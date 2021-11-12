/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:17:35 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/12 17:41:31 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->window);
	exit(EXIT_SUCCESS);
}

void	new_image(t_fdf *data)
{
	mlx_destroy_image(data->mlx.ptr, data->mlx.img.ptr);
	data->mlx.img = create_img(data->mlx);
	display_img(data);
}

void	put_controls(t_mlx mlx)
{
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 50, WHI, "CONTROLS");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 55, GRE, "________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 80, WHI, "Zoom: Scroll");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 100, WHI, "Move");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 105, GRE, "____");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 130, WHI, "W -> Up");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 150, GRE, "S -> Down");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 170, WHI, "A -> Left");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 190, WHI, "D -> Right");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 220, WHI, "Projection");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 225, GRE, "__________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 250, WHI, "ISO -> I");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 270, WHI, "PLAN -> P");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 290, WHI, "OBLIQUE -> O");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 320, WHI, "Rotation: Arrows");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 325, GRE, "________________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 350, WHI, "Left -> X Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 370, WHI, "Right -> Y Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 390, WHI, "Up -> Z Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 410, WHI, "Down -> Reset");
}

t_img	create_img(t_mlx mlx)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
	img.data = mlx_get_data_addr(img.ptr, &img.bbp,
			&img.size_line, &img.endian);
	if (!img.ptr || !img.data)
		show_error("Minilibx error");
	return (img);
}

t_mlx	create_window(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, "FDF");
	if (!mlx.ptr || !mlx.window)
		show_error("Minilibx Error");
	mlx.img = create_img(mlx);
	return (mlx);
}

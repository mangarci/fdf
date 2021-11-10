/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:17:35 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/10 22:25:24 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void    close_window(t_mlx *mlx)
{
    mlx_destroy_image(mlx->ptr, mlx->img.ptr);
    mlx_destroy_window(mlx->ptr, mlx->window);
    exit(EXIT_SUCCESS);
}

void    create_img(t_mlx mlx)
{
    t_img   img;
    img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
    img.data = mlx_get_data_addr(img.ptr, &img.bbp, &img.size_line, &img.endian);
    if (!img.ptr || !img.data)
        show_error("Minilibx error");
    return (img);
}
void    new_image(t_fdf *data)
{
    mlx_destroy_image(data->mlx.ptr, data->mlx.img.ptr);
    data->mlx.img = create_img(data->mlx);
    display_img(data);
}

void    create_window(void)
{
    t_mlx   mlx;
    mlx.ptr = mlx_init();
    mlx.window = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, "FDF");
    if (!mlx.ptr || !mlx.window)
        show_error("Minilibx Error");
    mlx.img = create_img(mlx);
    return (mlx);
}

void	put_controls(t_mlx mlx)
{
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 50, 0xffffff, "CONTROLS");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 55, 0x00ff00, "________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 80, 0xffffff, "Zoom: Scroll");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 100, 0xffffff, "Move");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 105, 0x00ff00, "____");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 130, 0xffffff, "W -> Up");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 150, 0xffffff, "S -> Down");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 170, 0xffffff, "A -> Left");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 190, 0xffffff, "D -> Right");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 220, 0xffffff, "Projection");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 225, 0x00ff00, "__________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 250, 0xffffff, "ISO -> I");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 270, 0xffffff, "PLAN -> P");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 290, 0xffffff, "OBLIQUE -> O");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 320, 0xffffff, "Rotation: Arrows");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 325, 0x00ff00, "________________");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 350, 0xffffff, "Left -> X Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 370, 0xffffff, "Right -> Y Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 390, 0xffffff, "Up -> Z Axis");
	mlx_string_put(mlx.ptr, mlx.window, 200 / 4, 410, 0xffffff, "Down -> Reset");
}
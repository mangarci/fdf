/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:17:35 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/10 21:19:50 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
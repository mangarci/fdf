/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:03 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 19:06:21 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

int array_length(char **array)
{
    int i;

    i = 0;
    if (!array)
        return (-1);
    while (array[i])
        i++;
    return (i);
}

void    cam_mov(int keycode, t_fdf *data)
{
    if (keycode == K_LEFT)
        data->cam.rotate[0] = 1;
    if (keycode == K_RIGHT)
        data->cam.rotate[1] = 1;
    if (keycode == K_UP)
        data->cam.rotate[2] = 1;
    if (keycode == K_DOWN)
    {
        data->cam.rotate[0] = 0;
        data->cam.rotate[1] = 0;
        data->cam.rotate[2] = 0;
        data->cam.angle = 0;
    }
    if (keycode == K_LEFT || keycode == K_RIGHT || keycode == K_UP)
        data->cam.angle += 0.1;
}

int zoom_bonus(int button, int x, int y, t_fdf *data)
{
    x++;
    y++;
    if (button == M_SCR_U && data->cam.zoom)
        data->cam.zoom += 1;
    if (button == M_SCR_D && data->cam.zoom)
        data->cam.zoom -= 1;
    if (!data->cam.zoom)
        data->cam.zoom = 1;
    new_image(data);
    return (0);
}
int main(int argc, char **argv)
{
    t_fdf   *data;
    data = (t_fdf *)malloc(sizeof(t_fdf));
    manage_errors(argc, argv);
    data->map = parse_map(argv[1]);
    data->cam = init_cam(data);
    data->mlx = create_window();
    display_img(data);
    hook_loop(data);
    return (0);
}
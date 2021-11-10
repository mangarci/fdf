/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:03 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/10 21:20:27 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int array_length(void **array)
{
    int i;

    i = 0;
    if (!array)
        return (-1);
    while (array[i])
        i++;
    return (i);
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
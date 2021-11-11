/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:22:46 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 17:02:04 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

int show_error(char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
    return (0);
}

void check_map(int argc, char **argv)
{
    if (argc != 2 || argv[1] == NULL)
        show_error("No map detected | Exit");
}

void check_extension(char **argv)
{
    char    *extension;

    extension = ft_strchr(argv[1], '.');
    if (!extension || ft_strcmp(extension, ".fdf"))
        show_error("Map extension .fdf not detected");
}

void    manage_errors(int argc, char **argv)
{
    check_map(argc, argv);
    check_extension(argv);
}
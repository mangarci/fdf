/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:25:48 by mangarci          #+#    #+#             */
/*   Updated: 2021/11/11 21:26:57 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line_bonus.h"
# include "key_macos.h"

# define ZOOM 30
# define SIZE_X 1600
# define SIZE_Y 1200

typedef struct t_cam
{
	int		pos_x;
	int		pos_y;
	int		zoom;
	float	angle;
	float	perspective_angle;
	int		isometric;
	int		plane;
	int		oblique;
	int		rotate[3];
}	t_cam;

typedef struct t_img
{
	void	*ptr;
	int		bbp;
	int		endian;
	int		size_line;
	char	*data;
}	t_img;

typedef struct t_mlx
{
	void			*ptr;
	void			*window;
	t_img			img;
	unsigned int	color;
	int				z_temp;
	int				aux;
}	t_mlx;

typedef struct t_range
{
	int		max;
	int		min;
	int		range;
}	t_range;

typedef struct t_map
{
	int		**map;
	char	**buffer;
	char	*line;
	int		width;
	int		height;
	int		fd;
	t_range	range;
}	t_map;

typedef struct t_fdf
{
	t_map	map;
	t_mlx	mlx;
	t_cam	cam;
}	t_fdf;

typedef struct t_lowvars
{
	int		dx;
	int		dy;
	int		yi;
	int		d;
	int		y;
}	t_lowvars;

typedef struct t_highvars
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;
}	t_highvars;

typedef struct t_point
{
	int	x;
	int	y;
}	t_point;

void	modifications(t_point *p0, t_point *p1, int z[2], t_fdf *data);
void	isometric(int *x, int *y, int z, double angle);
void	lowplotline(t_point p0, t_point p1, t_fdf *data);
void	highplotline(t_point p0, t_point p1, t_fdf *data);
void	plotline(t_point p0, int x1, int y1, t_fdf *data);
void	perform_zoom(t_point *p0, t_point *p1, int z[2], t_fdf *data);
void	perform_position(t_point *p0, t_point *p1, t_fdf *data);
void	hooks_perspective(t_fdf *data, int keycode);
int		show_error(char *error);
void	check_map(int argc, char **argv);
void	check_extension(char **argv);
void	manage_errors(int argc, char **argv);
void	x_rotation(int *y, int *z, double angle);
void	y_rotation(int *x, int *z, double angle);
void	z_rotation(int *x, int *y, double angle);
void	rotate(int *x, int *y, int *z, t_fdf *data);
int		array_length(char **array);
void	cam_mov(int keycode, t_fdf *data);
int		zoom_bonus(int button, int x, int y, t_fdf *data);
int		set_color(int x, int y, t_map map, t_range r);
void	mine_mlx_pixel_put(t_fdf *data, int x, int y);
void	display_img(t_fdf *data);
int		double_free(char **array);
t_range	range(t_fdf *data);
int		key_action(int keycode, t_fdf *data);
int		close_x(t_mlx *mlx);
void	hook_loop(t_fdf *data);
int		zoom(int size);
t_cam	init_cam(t_fdf *data);
int		open_map(char *map_name);
int		get_height(char *filename);
int		get_width(char *filename);
void	fill(char *line, int *map_line);
t_map	parse_map(char *filename);
void	close_window(t_mlx *mlx);
t_img	create_img(t_mlx mlx);
void	new_image(t_fdf *data);
t_mlx	create_window(void);
void	put_controls(t_mlx mlx);

#endif

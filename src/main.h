/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/05/02 17:02:05 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define XK_MISCELLANY
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/X.h>
# include "../includes/ft_printf.h"
# include "../includes/get_next_line_bonus.h"
# include "../includes/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
# define BAILOUT_RADIUS 1000

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct	s_fractal
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	const_x;
	double	const_y;
	double	zoom;
}	t_fractal;

// From mandelbrot.c
unsigned int	generate_mandelbrot_point(double x, double y, int iteration);
void			ft_output_mandelbrot(t_data data);

// From julia.c
unsigned int	generate_julia_point(double x, double y, double cx, double cy, int iteration);
void			ft_output_julia(t_data data, double cx, double cy);

// From keyevents.c
int	ft_close(t_data *data);
int	ft_keypress(int keycode, t_data *data);

// From mlx_helper.c
void	pixel_to_image(t_data *data, int x, int y, int color);

// From mouse_events.c
int		ft_mouse_zoom(int keycode, t_data *data, t_fractal *fractal);

// From atof.c
double	ft_atof(char *s);

#endif
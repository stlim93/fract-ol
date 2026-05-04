/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 20:49:39 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define XK_MISCELLANY
# define XK_LATIN1
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
# define MAX_ITER 100
# define MAX_X (*data).max_x
# define MIN_X (*data).min_x
# define MAX_Y (*data).max_y
# define MIN_Y (*data).min_y
# define SIZE_LINE (*data).size_line
# define MLX (*data).mlx_ptr
# define WIN (*data).win_ptr
# define IMG (*data).img_ptr

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;
	double	const_x;
	double	const_y;
	double	offset_x;
	double	offset_y;
}	t_data;

// From mandelbrot.c
unsigned int	generate_mandelbrot_point(double x, double y, int iteration);
void			ft_output_mandelbrot(t_data *data);
int				ft_put_mandelbrot_to_window(t_data *data);

// From julia.c
unsigned int	generate_julia_point(double x, double y, double cx, double cy, int iteration);
void			ft_output_julia(t_data data, double cx, double cy);

// From keyevents.c
int	ft_close(t_data *data);
int	ft_keypress(int keycode, t_data *data);
int	ft_keypress2(int keycode, t_data *data);
int ft_buttonpress(int buttoncode, int x, int y, t_data *data);

// From mlx_helper.c
void	pixel_to_image(t_data *data, int x, int y, int color);

// From atof.c
double	ft_atof(char *s);

#endif
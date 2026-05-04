/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/05/05 00:01:56 by steve            ###   ########.fr       */
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

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 200
# define MAX_X (*data).max_x
# define MIN_X (*data).min_x
# define MAX_Y (*data).max_y
# define MIN_Y (*data).min_y
# define SIZE_LINE (*data).size_line
# define MLX (*data).mlx_ptr
# define WIN (*data).win_ptr
# define IMG (*data).img_ptr
# define CONST_X (*data).const_x
# define CONST_Y (*data).const_y

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
unsigned int	generate_mandelbrot_point(double x, double y);
void			ft_output_mandelbrot(t_data *data);
int				ft_put_mandelbrot_to_window(t_data *data);

// From julia.c
unsigned int	generate_julia_point(double x, double y, double cx, double cy);
int				ft_put_julia_to_window(t_data *data);
void			ft_output_julia(t_data *data, double const_x, double const_y);

// From keyevents.c
int				ft_close(t_data *data);
int				ft_keypress(int keycode, t_data *data);
int 			ft_buttonpress(int buttoncode, int x, int y, t_data *data);

// From events_update.c
void			ft_move(char c, t_data *data);
void			ft_move2(char c, t_data *data);

// From mlx_helper.c
void			pixel_to_image(t_data *data, int x, int y, int color);

// From atof.c
double			ft_atof(char *s);

// From colour.c
unsigned int	create_rgb(int iter, double radius);

#endif
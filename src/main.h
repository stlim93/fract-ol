/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/05/05 21:01:17 by stelim           ###   ########.fr       */
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
# include <limits.h>
# include <X11/keysymdef.h>
# include <X11/X.h>
# include "../includes/ft_printf.h"
# include "../includes/get_next_line_bonus.h"
# include "../includes/libft.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 50

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
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
unsigned int	ft_mandelbrot_point(double x, double y);
void			ft_output_mandelbrot(t_data *data);
int				ft_put_mandelbrot_to_window(t_data *data);

// From julia.c
unsigned int	ft_julia_point(double x, double y, double cx, double cy);
int				ft_put_julia_to_window(t_data *data);
void			ft_output_julia(t_data *data, double const_x, double const_y);

// From mandelbar.c
unsigned int	ft_mandelbar_point(double x, double y);
void			ft_output_mandelbar(t_data *data);
int				ft_put_mandelbar_to_window(t_data *data);

// From keyevents.c
int				ft_close(t_data *data);
int				ft_keypress(int keycode, t_data *data);
int				ft_buttonpress(int buttoncode, int x, int y, t_data *data);

// From events_update.c
void			ft_move(char c, t_data *data);
void			ft_move2(char c, t_data *data);

// From mlx_helper.c
void			pixel_to_image(t_data *data, int x, int y, int color);

// From atof.c
double			ft_atof(char *s);
void			ft_output_error(void);

// From colour.c
unsigned int	create_rgb(int iter, double radius);

#endif
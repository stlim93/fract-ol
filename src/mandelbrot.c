/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:20:13 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 20:51:47 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

unsigned int	mandelbrot_rgb(int iter, double radius)
{
	double	x;
	int		r;
	int		g;
	int		b;

	if (radius < 2)
		return (0x000000);
	else
	{
		x = (iter) - log(log(radius) / log(2)) / log(2);
	}
	r = (sin(1.0 / 3.0 * x) * 127 + 128);
	g = (sin(1.0 / 3.0 * x + 2.0 / 3.0 * M_PI) * 127 + 128);
	b = (sin(1.0 / 3.0 * x + 4.0 / 3.0 * M_PI) * 127 + 128);
	return (r << 16 | g << 8 | b);
}

unsigned int	generate_mandelbrot_point(double x, double y, int iteration)
{
	int		iter;
	double	re;
	double	im;
	double	radius;
	double	re_temp;

	iter = 0;
	re = x;
	im = y;
	while (iter < iteration && pow(re, 2) + pow(im, 2) < 4)
	{
		re_temp = re * re - im * im + x;
		im = 2 * (re * im) + y;
		re = re_temp;
		iter++;
	}
	radius = sqrt(pow(re, 2) + pow(im, 2));
	return (mandelbrot_rgb(iter, radius));
}

void	ft_init_mandelbrot(t_data *data)
{
	(*data).min_x = -2.0;
	(*data).max_x = 2.0;
	(*data).min_y = -2.0;
	(*data).max_y = 2.0;
	(*data).zoom = 0.05;
	(*data).const_x = 0.0;
	(*data).const_y = 0.0;
}

int	ft_put_mandelbrot_to_window(t_data *data)
{
	double	pos_y;
	double	pos_x;
	double	scaled_x;
	double	scaled_y;
	double	colour;

	pos_y = 0;
	while (pos_y < HEIGHT)
	{
		pos_x = 0;
		while (pos_x < WIDTH)
		{
			scaled_x = pos_x * (MAX_X - MIN_X) / (WIDTH - 1) + MIN_X;
			scaled_y = - (pos_y * (MAX_Y - MIN_Y) / (HEIGHT - 1)) + MAX_Y;
			colour = generate_mandelbrot_point(scaled_x, scaled_y, MAX_ITER);
			pixel_to_image(data, pos_x * SIZE_LINE / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void	ft_output_mandelbrot(t_data *data)
{
	ft_init_mandelbrot(data);
	mlx_key_hook(data->win_ptr, ft_keypress, data);
	mlx_mouse_hook(data->win_ptr, ft_buttonpress, data);
	mlx_loop_hook(data->mlx_ptr, ft_put_mandelbrot_to_window, data);
}

// ft_put_mandelbrot_to_window(data);
// mlx_hook((*data).win_ptr, ButtonPress,
// ButtonPressMask, &ft_buttonpress, data);
// mlx_loop_hook(data->mlx_ptr, ft_put_mandelbrot_to_window, data);
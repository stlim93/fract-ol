/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:20:13 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 00:42:49 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

unsigned int	mandelbrot_rgb(int iter, double radius)
{
	// double	x;

	if (radius <= 2)
		return (0); //x = 0;
	// else
	// {
	// 	x = (iter) - log(log(radius) / log(BAILOUT_RADIUS)) / log(2);
	// }
	return (iter << 16 | iter << 8 | iter);
	// return (x);
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
		re_temp = re*re - im*im + x;
		im = 2 * (re*im) + y;
		re = re_temp;
		iter++;
	}
	radius = sqrt(pow(re, 2) + pow(im, 2));
	return (mandelbrot_rgb(iter,radius));
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

static int ft_put_mandelbrot_to_window(t_data *data)
{
	double	pos_y;
	double	pos_x;
	double	scaled_x;
	double	scaled_y;
	double	colour;
	
	pos_y=0;
	while (pos_y < HEIGHT)
	{
		pos_x = 0;
		while (pos_x < WIDTH)
		{
			scaled_x = (double) pos_x * ((*data).max_x - (*data).min_x) / (WIDTH - 1) + (*data).min_x;
			scaled_y = - ((double) pos_y * ((*data).max_y - (*data).min_y) / (HEIGHT - 1)) + (*data).max_y;
			colour = generate_mandelbrot_point(scaled_x, scaled_y, MAX_ITER);
			pixel_to_image(&(*data), pos_x * (*data).size_line / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_clear_window((*data).mlx_ptr, (*data).win_ptr);
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr, (*data).img_ptr, 0, 0);
	return (0);
}

void	ft_output_mandelbrot(t_data *data)
{
	ft_init_mandelbrot(data);
	ft_put_mandelbrot_to_window(data);
	mlx_hook((*data).win_ptr, ButtonPress, ButtonPressMask, &ft_buttonpress, data);
	mlx_loop_hook(data->mlx_ptr, ft_put_mandelbrot_to_window, data);
}

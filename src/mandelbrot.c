/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:20:13 by stelim            #+#    #+#             */
/*   Updated: 2026/05/01 15:56:02 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

unsigned int	mandelbrot_rgb(int iter, double radius)
{
	double x;

	if (radius <= 2)
		x = 0;
	else
		x = (1 << 8) * (iter + 1) - log(log(radius) / log(2)) / log(2);
	return (x);
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

void	ft_init_mandelbrot(t_fractal *mdb)
{
	(*mdb).min_x = -2;
	(*mdb).max_x = 2;
	(*mdb).min_y = -2;
	(*mdb).max_y = 2;
	(*mdb).zoom = 1;
	(*mdb).const_x = 0;
	(*mdb).const_y = 0;
}

void	ft_output_mandelbrot(t_data data)
{
	t_fractal	mdb;
	double	pos_y;
	double	pos_x;
	double	scaled_x;
	double	scaled_y;
	double	colour;
	
	ft_init_mandelbrot(&mdb);
	pos_y=0;
	while (pos_y < HEIGHT)
	{
		pos_x = 0;
		while (pos_x < WIDTH)
		{
			scaled_x = (double) pos_x * (mdb.max_x - mdb.min_x) / WIDTH - 2;
			scaled_y = - ((double) pos_y * (mdb.max_y - mdb.min_y) / HEIGHT) + 2;
			colour = generate_mandelbrot_point(scaled_x, scaled_y, MAX_ITER);
			pixel_to_image(&data, pos_x * data.size_line / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
}
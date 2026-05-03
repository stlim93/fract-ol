/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:01:43 by stelim            #+#    #+#             */
/*   Updated: 2026/05/03 17:13:30 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	julia_rgb(int iter, double radius)
{
	double x;

	if (radius <= 2)
		x = 0;
	else
		x = (1 << 8) * (iter + 1) - log(log(radius) / log(2)) / log(2);
	return (x);
}

unsigned int	generate_julia_point(double x, double y, double cx, double cy, int iteration)
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
		re_temp = re*re - im*im + cx;
		im = 2 * (re*im) + cy;
		re = re_temp;
		iter++;
	}
	radius = pow(re, 2) + pow(im, 2);
	return (julia_rgb(iter, sqrt(radius)));
}

void	ft_init_julia(t_data *data)
{
	(*data).min_x = -2;
	(*data).max_x = 2;
	(*data).min_y = -2;
	(*data).max_y = 2;
	(*data).const_x = 0;
	(*data).const_y = 0;
}

void	ft_output_julia(t_data data, double cx, double cy)
{
	double	pos_y;
	double	pos_x;
	double	scaled_x;
	double	scaled_y;
	double	colour;
	
	ft_init_julia(&data);
	pos_y=0;
	while (pos_y < HEIGHT)
	{
		pos_x = 0;
		while (pos_x < WIDTH)
		{
			scaled_x = (double) pos_x * (data.max_x - data.min_x) / WIDTH - 2;
			scaled_y = - ((double) pos_y * (data.max_y - data.min_y) / HEIGHT) + 2;
			colour = generate_julia_point(scaled_x, scaled_y, cx, cy, MAX_ITER);
			pixel_to_image(&data, pos_x * data.size_line / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
}
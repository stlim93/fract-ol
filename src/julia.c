/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:01:43 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 21:13:12 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	generate_julia_point(double x, double y, double cx, double cy)
{
	int		iter;
	double	re;
	double	im;
	double	radius;
	double	re_temp;

	iter = 0;
	re = x;
	im = y;
	while (iter < MAX_ITER && pow(re, 2) + pow(im, 2) < 4)
	{
		re_temp = re * re - im * im + cx;
		im = 2 * (re * im) + cy;
		re = re_temp;
		iter++;
	}
	radius = pow(re, 2) + pow(im, 2);
	return (create_rgb(iter, sqrt(radius)));
}

void	ft_init_julia(t_data *data, double const_x, double const_y)
{
	(*data).min_x = -2;
	(*data).max_x = 2;
	(*data).min_y = -2;
	(*data).max_y = 2;
	(*data).const_x = const_x;
	(*data).const_y = const_y;
}

int	ft_put_julia_to_window(t_data *data)
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
			scaled_y = -pos_y * (MAX_Y - MIN_Y) / (HEIGHT - 1) + MAX_Y;
			colour = generate_julia_point(scaled_x, scaled_y, CONST_X, CONST_Y);
			pixel_to_image(data, pos_x * SIZE_LINE / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void	ft_output_julia(t_data *data, double const_x, double const_y)
{
	ft_init_julia(data, const_x, const_y);
	mlx_key_hook(WIN, ft_keypress, data);
	mlx_mouse_hook(WIN, ft_buttonpress, data);
	mlx_loop_hook(MLX, ft_put_julia_to_window, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:01:43 by stelim            #+#    #+#             */
/*   Updated: 2026/05/05 19:53:27 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	ft_julia_point(double x, double y, double cx, double cy)
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

void	ft_init_julia(t_data *d, double const_x, double const_y)
{
	(*d).min_x = -2;
	(*d).max_x = 2;
	(*d).min_y = -2;
	(*d).max_y = 2;
	(*d).zoom = 0.05;
	(*d).const_x = const_x;
	(*d).const_y = const_y;
}

int	ft_put_julia_to_window(t_data *d)
{
	double	pos_y;
	double	pos_x;
	double	s_x;
	double	s_y;
	double	colour;

	pos_y = 0;
	while (pos_y < HEIGHT)
	{
		pos_x = 0;
		while (pos_x < WIDTH)
		{
			s_x = pos_x * ((*d).max_x - (*d).min_x) / (WIDTH - 1);
			s_x += (*d).min_x;
			s_y = -pos_y * ((*d).max_y - (*d).max_y) / (HEIGHT - 1);
			s_y += (*d).max_y;
			colour = ft_julia_point(s_x, s_y, (*d).const_x, (*d).const_y);
			pixel_to_image(d, pos_x * (*d).size_line / WIDTH, pos_y, colour);
			pos_x++;
		}
		pos_y++;
	}
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (0);
}

void	ft_output_julia(t_data *d, double const_x, double const_y)
{
	ft_init_julia(d, const_x, const_y);
	mlx_key_hook(d->win_ptr, &ft_keypress, d);
	mlx_mouse_hook(d->win_ptr, &ft_buttonpress, d);
	mlx_loop_hook(d->mlx_ptr, &ft_put_julia_to_window, d);
}

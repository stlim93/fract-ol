/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:20:13 by stelim            #+#    #+#             */
/*   Updated: 2026/04/26 20:41:59 by stelim           ###   ########.fr       */
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
	radius = re * re + im * im;
	return (mandelbrot_rgb(iter, fabs(radius)));
}

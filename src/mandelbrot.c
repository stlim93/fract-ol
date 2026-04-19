/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:20:13 by stelim            #+#    #+#             */
/*   Updated: 2026/04/19 16:46:52 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
// z(n) = z(n-1)^2+c, c = x+iy;
// >> z(1) = z(0)^2 + x+iy; z(0) = x+iy; z(1) = x^2 + 2xyi+y^2 + x + iy;
// >> z(1) = x^2+y^2 + x + i(2x+1)y;

double generate_mandelbrot_point(double x, double y, int iteration)
{
	int		iter;
	double	re;
	double	im;
	double	radius;

	iter = 0;
	re = x;
	im = y;
	radius = re*re + im*im;
	while (iter < iteration && fabs(radius) < 4)
	{
		re = re*re - im*im + x;
		im = 2 * (re*im) + y;
		radius = re*re + im*im;
		iter++;
	}
	return (radius);
}

int main(void)
{
	double x = sqrt(generate_mandelbrot_point(0.1, 0, 100));
	
	printf("%f\n", x);
}

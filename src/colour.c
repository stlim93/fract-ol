/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:01:10 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 21:09:58 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	create_rgb(int iter, double radius)
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

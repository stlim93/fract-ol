/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:14:59 by stelim            #+#    #+#             */
/*   Updated: 2026/05/01 15:49:29 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Button4 - Zoom in
// Button5 - Zoom out

int	ft_mouse_zoom(int keycode, t_data *data)
{
	if (keycode == Button4)
		ft_output_mandelbrot(*data);
	return (0);
}
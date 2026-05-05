/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:24:47 by stelim            #+#    #+#             */
/*   Updated: 2026/05/05 20:17:51 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	int	pixel_offset;
	int	bytes_per_pixel;

	bytes_per_pixel = data->bpp / 8;
	pixel_offset = (y * data->size_line) + (x + bytes_per_pixel);
	*(unsigned int *)(data->img_data + pixel_offset) = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/04/19 14:01:25 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	int	pixel_offset;
	int	bytes_per_pixel;

	bytes_per_pixel = data->bits_per_pixel / 8;
	pixel_offset = (y * data->size_line) + (x + bytes_per_pixel);
	*(unsigned int *)(data->img_data + pixel_offset) = color;
}

#endif
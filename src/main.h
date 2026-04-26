/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:02:42 by stelim            #+#    #+#             */
/*   Updated: 2026/04/26 20:55:10 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define XK_MISCELLANY
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
# define BAILOUT_RADIUS 1000

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

// From mandelbrot.c
unsigned int	generate_mandelbrot_point(double x, double y, int iteration);

// From keyevents.c
int	ft_close(t_data *data);
int	ft_keypress(int keycode, t_data *data);

// From mlx_helper.c
void	pixel_to_image(t_data *data, int x, int y, int color);

#endif
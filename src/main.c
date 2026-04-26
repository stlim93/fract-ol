/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:04:53 by stelim            #+#    #+#             */
/*   Updated: 2026/04/26 16:46:27 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img_data = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.size_line, &data.endian);
	
	int i_y;
	int i_x;
	double scaled_x;
	double scaled_y;
	unsigned int colour;
	i_y=0;
	while (i_y < HEIGHT)
	{
		i_x = 0;
		while (i_x < WIDTH)
		{
			scaled_x = (double) i_x * 4 / WIDTH - 2;
			scaled_y = - ((double) i_y * 4 / HEIGHT) + 2;
			colour = generate_mandelbrot_point(scaled_x, scaled_y, MAX_ITER);
			pixel_to_image(&data, i_x * data.size_line / WIDTH, i_y, colour);
			i_x++;
		}
		i_y++;
	}
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);

	//  List of mouse and key actions
	mlx_hook(data.win_ptr, 17, 1 << 17, &ft_close, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_loop(data.mlx_ptr);

	// // CLEAR ALL THESE SHITS IN SEQUENCE
	// // mlx_destroy_image(data.mlx_ptr, data.img_ptr);
	// // mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	// // mlx_destroy_display(data.mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:04:53 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 21:10:33 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	if ((argc != 2) && (argc != 4))
	{
		perror("Either specify './fractol mandelbrot' or './fractol julia cx cy'");
		exit(EXIT_FAILURE);
	}

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

	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		ft_output_mandelbrot(&data);
	else if(ft_strncmp(argv[1], "julia", 6) == 0)
	{
		ft_output_julia(&data, ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
	{
		ft_printf("error: Select julia or mandelbrot set");
		exit(EXIT_FAILURE);
	}

	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}



	// // CLEAR ALL THESE SHITS IN SEQUENCE
	// // mlx_destroy_image(data.mlx_ptr, data.img_ptr);
	// // mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	// // mlx_destroy_display(data.mlx_ptr);

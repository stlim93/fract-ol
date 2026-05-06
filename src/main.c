/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:04:53 by stelim            #+#    #+#             */
/*   Updated: 2026/05/06 21:52:43 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_data	ft_init_mlx(void)
{
	t_data	d;

	d.mlx_ptr = mlx_init();
	if (!d.mlx_ptr)
		exit(EXIT_FAILURE);
	d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!d.win_ptr)
	{
		free(d.mlx_ptr);
		exit(EXIT_FAILURE);
	}
	d.img_ptr = mlx_new_image(d.mlx_ptr, WIDTH, HEIGHT);
	d.img_data = mlx_get_data_addr(d.img_ptr, &d.bpp, &d.size_line, &d.endian);
	return (d);
}

void	ft_output_guide(void)
{
	ft_printf(" ========================== GUIDE =========================\n");
	ft_printf("| This program offers 3 fractals: Mandelbrot, Tricorn and  |\n");
	ft_printf("| Julia.                                                   |\n");
	ft_printf("|                                                          |\n");
	ft_printf("| To display Mandelbrot simply type ./fractal mandelbrot.  |\n");
	ft_printf("| To display tricorn simply type ./fractal tricorn.        |\n");
	ft_printf("| Otherwise input ./fractal julia <X> <Y> for Julia fractal|\n");
	ft_printf("| <X> and <Y> must be float or integer.                    |\n");
	ft_printf("|                                                          |\n");
	ft_printf("| Controls:                                                |\n");
	ft_printf("|  - Arrow keys: to move around the map.                   |\n");
	ft_printf("|  - C key: to return to initial map.                      |\n");
	ft_printf("|  - '-' or '=' key: to zoom in or out.                    |\n");
	ft_printf("|  - mouse scroll wheel: to zoom in or out infinitely at   |\n");
	ft_printf("|    the cursor.                                           |\n");
	ft_printf("|  - ESC key or close window button: to quit the program.  |\n");
	ft_printf(" ==========================================================\n");
}

int	ft_detect_fractal(char *s[], int argc)
{
	if (ft_strncmp(s[1], "mandelbrot", 10) == 0 && argc == 2)
		return (1);
	else if (ft_strncmp(s[1], "mandelbar", 9) == 0 && argc == 2)
		return (2);
	else if (ft_strncmp(s[1], "tricorn", 7) == 0 && argc == 2)
		return (2);
	else if (ft_strncmp(s[1], "julia", 5) == 0 && argc == 4)
	{
		if (ft_atof(s[2]) && ft_atof(s[3]))
			return (3);
		else
			exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data	d;
	int		type;

	ft_output_guide();
	if (argc == 2 || argc == 4)
		type = ft_detect_fractal(argv, argc);
	else
		exit(EXIT_FAILURE);
	d = ft_init_mlx();
	if (type == 1 && argc == 2)
		ft_output_mandelbrot(&d);
	else if (type == 2 && argc == 2)
		ft_output_mandelbar(&d);
	else if (type == 3 && argc == 4)
		ft_output_julia(&d, ft_atof(argv[2]), ft_atof(argv[3]));
	else
		exit(EXIT_FAILURE);
	mlx_hook(d.win_ptr, DestroyNotify, StructureNotifyMask, &ft_close, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}

// CLEAR ALL THESE IN SEQUENCE TO PREVENT MEMLEAK
// mlx_destroy_image(data.mlx_ptr, data.img_ptr);
// mlx_destroy_window(data.mlx_ptr, data.win_ptr);
// mlx_destroy_display(data.mlx_ptr);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:45:51 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 00:50:59 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void ft_update_parameters(int dir, int x, int y, t_data *data)
{
	double	coord;
	double	old_range;
	double	new_range;
	double	scale;

	scale = 1 - (*data).zoom;
	if (dir == -1)
		scale = 1/scale;
	old_range = (*data).max_x - (*data).min_x;
	coord = x * old_range / (WIDTH - 1) + (*data).min_x;
	// printf("coord x = %.15f ", coord);
	new_range = scale * old_range;
	(*data).min_x = coord - (coord - (*data).min_x) / old_range * new_range;
	(*data).max_x = (*data).min_x + new_range;
	old_range = (*data).max_y - (*data).min_y;
	coord = (*data).max_y - y * old_range / (HEIGHT - 1);
	// printf("coord y = %.15f\n", coord);
	new_range = scale * old_range;
	(*data).max_y = coord - (coord - (*data).max_y) / old_range * new_range;
	(*data).min_y = (*data).max_y - new_range;
}

int	ft_close(t_data *data)
{
	if(data)
	{
		if (data->img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
	}
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data);
	else if (keycode == XK_equal)
	{
		printf("Zoom in via + sign\n");
	}
	else if (keycode == XK_minus)
	{
		printf("Zoom out via - sign\n");
	}
	else
		ft_keypress2(keycode, data);
	return(0);
}

int	ft_keypress2(int keycode, t_data *data)
{
	if (keycode == XK_Up)
	{
		printf("Move up via up arrow key\n");
	}
	else if (keycode == XK_Down)
	{
		printf("Move down via down arrow key\n");
	}
	else if (keycode == XK_Left)
	{
		printf("Move left via left arrow key\n");
	}
	else if(keycode == XK_Right)
	{
		printf("Move right via right arrow key\n");
	}
	return (0);
}

int	ft_buttonpress(int buttoncode, int x, int y, t_data *data)
{
	(void) x;
	(void) y;

	if (buttoncode == Button4)
		ft_update_parameters(1, x, y, data);
	else if (buttoncode == Button5)
		ft_update_parameters(-1, x, y, data);
	return (0);
}
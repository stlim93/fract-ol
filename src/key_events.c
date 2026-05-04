/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:45:51 by stelim            #+#    #+#             */
/*   Updated: 2026/05/04 21:00:42 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_update_parameters(int dir, int x, int y, t_data *data)
{
	double	coord;
	double	old_range;
	double	new_range;
	double	scale;

	scale = 1 - (*data).zoom;
	if (dir == -1)
		scale = 1 / scale;
	else if (dir == 0)
		scale = 1;
	old_range = MAX_X - MIN_X;
	coord = x * old_range / (WIDTH - 1) + MIN_X;
	new_range = scale * old_range;
	MIN_X = coord - (coord - MIN_X) / old_range * new_range;
	MAX_X = MIN_X + new_range;
	old_range = MAX_Y - MIN_Y;
	coord = MAX_Y - y * old_range / (HEIGHT - 1);
	new_range = scale * old_range;
	MAX_Y = coord - (coord - MAX_Y) / old_range * new_range;
	MIN_Y = MAX_Y - new_range;
}

int	ft_close(t_data *data)
{
	if (data)
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
		ft_update_parameters(1, WIDTH / 2, HEIGHT / 2, data);
	else if (keycode == XK_minus)
		ft_update_parameters(-1, WIDTH / 2, HEIGHT / 2, data);
	else
		ft_keypress2(keycode, data);
	return (0);
}

int	ft_keypress2(int keycode, t_data *data)
{
	t_data	*x;

	x = data;
	if (keycode == XK_Up)
	{
		printf("Move up via down arrow key\n");
	}
	else if (keycode == XK_Down)
	{
		printf("Move down via down arrow key\n");
	}
	else if (keycode == XK_Left)
	{
		printf("Move left via left arrow key\n");
	}
	else if (keycode == XK_Right)
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

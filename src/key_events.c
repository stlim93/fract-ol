/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:45:51 by stelim            #+#    #+#             */
/*   Updated: 2026/05/03 18:27:59 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	// else if (keycode == XK_equal)
	// {
	// 	printf("Zoom in via + sign\n");
	// }
	// else if (keycode == XK_minus)
	// {
	// 	printf("Zoom out via - sign\n");
	// }
	else
		ft_keypress2(keycode, data);
	return(0);
}

int	ft_keypress2(int keycode, t_data *data)
{
	t_data x;

	x = *data;
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
	{
		printf("Scroll up = zoom in\n");
		if ((*data).zoom <= 0.00001)
			(*data).zoom = 0.00001;
		else
			(*data).zoom *= 0.95;
	}
	else if (buttoncode == Button5)
	{
		printf("Scroll down = zoom out\n");
		if ((*data).zoom >= 1.2)
			(*data).zoom = 1.2;
		else
			(*data).zoom /= 0.95;
	}
	return (0);
}
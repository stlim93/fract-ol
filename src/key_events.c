/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:45:51 by stelim            #+#    #+#             */
/*   Updated: 2026/05/05 19:49:29 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_update_parameters(int dir, int x, int y, t_data *d)
{
	double	coord;
	double	old_range;
	double	new_range;
	double	scale;

	scale = 1 - (*d).zoom;
	if (dir == -1)
		scale = 1 / scale;
	else if (dir == 0)
		scale = 1;
	old_range = (*d).max_x - (*d).min_x;
	coord = x * old_range / (WIDTH - 1) + (*d).min_x;
	new_range = scale * old_range;
	(*d).min_x = coord - (coord - (*d).min_x) / old_range * new_range;
	(*d).max_x = (*d).min_x + new_range;
	old_range = (*d).max_y - (*d).min_y;
	coord = (*d).max_y - y * old_range / (HEIGHT - 1);
	new_range = scale * old_range;
	(*d).max_y = coord - (coord - (*d).max_y) / old_range * new_range;
	(*d).min_y = (*d).max_y - new_range;
}

int	ft_close(t_data *d)
{
	if (d)
	{
		if (d->img_ptr)
			mlx_destroy_image(d->mlx_ptr, d->img_ptr);
		if (d->win_ptr)
			mlx_destroy_window(d->mlx_ptr, d->win_ptr);
		if (d->mlx_ptr)
		{
			mlx_destroy_display(d->mlx_ptr);
			free(d->mlx_ptr);
		}
	}
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_data *d)
{
	if (keycode == XK_Escape)
		ft_close(d);
	else if (keycode == XK_equal)
		ft_update_parameters(1, WIDTH / 2, HEIGHT / 2, d);
	else if (keycode == XK_minus)
		ft_update_parameters(-1, WIDTH / 2, HEIGHT / 2, d);
	else if (keycode == XK_Up)
		ft_move('U', d);
	else if (keycode == XK_Down)
		ft_move('D', d);
	else if (keycode == XK_Left)
		ft_move('L', d);
	else if (keycode == XK_Right)
		ft_move('R', d);
	else if (keycode == XK_c)
		ft_move('C', d);
	return (0);
}

int	ft_buttonpress(int buttoncode, int x, int y, t_data *d)
{
	(void) x;
	(void) y;
	if (buttoncode == Button4)
		ft_update_parameters(1, x, y, d);
	else if (buttoncode == Button5)
		ft_update_parameters(-1, x, y, d);
	return (0);
}

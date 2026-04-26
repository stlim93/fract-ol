/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:45:51 by stelim            #+#    #+#             */
/*   Updated: 2026/04/26 11:45:51 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_close(t_data *data)
{
	if(data)
	{
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
	if (keycode == 0xff1b)
		ft_close(data);
	return(0);
}
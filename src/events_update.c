/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:22:16 by steve             #+#    #+#             */
/*   Updated: 2026/05/05 00:17:45 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_move(char c, t_data *data)
{
	double	offset_x;
	double	offset_y;
    int     direction;

	offset_x  = (MAX_X - MIN_X) / 20;
	offset_y  = (MAX_Y - MIN_Y) / 20;
    direction = 1;
    if (c == 'D' || c == 'L')
    { 
        direction = -1;
    }
	if (c == 'U' || c == 'D')
	{
		MAX_Y = MAX_Y + direction * offset_y;
		MIN_Y = MIN_Y + direction * offset_y;	
	}
	else if (c == 'L' || c == 'R')
	{
		MAX_X = MAX_X + direction * offset_x;
		MIN_X = MIN_X + direction * offset_x;	
	}
	else 
        ft_move2(c, data);
}

void    ft_move2(char c, t_data *data)
{
    if (c == 'C')
    {
        MAX_X = 2;
        MIN_X = -2;
        MAX_Y = 2;
        MIN_Y = -2;
    }
}

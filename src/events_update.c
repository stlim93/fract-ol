/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:22:16 by steve             #+#    #+#             */
/*   Updated: 2026/05/05 19:56:16 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_move(char c, t_data *d)
{
	double	offset_x;
	double	offset_y;
	int		direction;

	offset_x = ((*d).max_x - (*d).min_x) / 20;
	offset_y = ((*d).max_y - (*d).min_y) / 20;
	direction = 1;
	if (c == 'D' || c == 'L')
	{
		direction = -1;
	}
	if (c == 'U' || c == 'D')
	{
		(*d).max_y += direction * offset_y;
		(*d).min_y += direction * offset_y;
	}
	else if (c == 'L' || c == 'R')
	{
		(*d).max_x += direction * offset_x;
		(*d).min_x += direction * offset_x;
	}
	else
		ft_move2(c, d);
}

void	ft_move2(char c, t_data *d)
{
	if (c == 'C')
	{
		(*d).max_x = 2;
		(*d).min_x = -2;
		(*d).max_y = 2;
		(*d).min_y = -2;
	}
}

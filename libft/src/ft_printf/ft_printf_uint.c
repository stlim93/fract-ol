/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:01:45 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:20 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_uint(unsigned int ui)
{
	if (ui < 10)
	{
		ui += '0';
		write(1, &ui, 1);
	}
	else
	{
		ft_uint(ui / 10);
		ft_uint(ui % 10);
	}
}

static int	ft_uint_size(unsigned int ui)
{
	int	ndigits;

	ndigits = 0;
	if (ui == 0)
		return (1);
	while (ui > 0)
	{
		ndigits++;
		ui /= 10;
	}
	return (ndigits);
}

int	ft_printf_uint(unsigned int ui)
{
	ft_uint(ui);
	return (ft_uint_size(ui));
}

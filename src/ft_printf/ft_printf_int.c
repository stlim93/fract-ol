/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:56:30 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:08 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_ndigits(int i)
{
	int	ndigits;

	ndigits = 0;
	if (i == 0)
		ndigits++;
	else if (i < 0)
		ndigits += 2;
	if (i < -9)
		i = -(i / 10);
	while (i > 0)
	{
		i /= 10;
		ndigits++;
	}
	return (ndigits);
}

int	ft_printf_int(int i)
{
	int		nbr;
	int		ndigits;

	ndigits = ft_ndigits((long int) i);
	if (i < 0)
	{
		write(1, "-", 1);
		if (i < -9)
			ft_printf_int(-(i / 10));
		ft_printf_int(-(i % 10));
	}
	else if (i > 9)
	{
		ft_printf_int(i / 10);
		ft_printf_int(i % 10);
	}
	else
	{
		nbr = i + '0';
		write(1, &nbr, 1);
	}
	return (ndigits);
}

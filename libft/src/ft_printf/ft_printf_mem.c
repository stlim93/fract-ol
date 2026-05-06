/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:25:28 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:12 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_mem(unsigned long int addr, int *ndigits)
{
	char	*hexadecimal;

	hexadecimal = "0123456789abcdef";
	if (addr < 16)
	{
		*ndigits = *ndigits + 1;
		write(1, &hexadecimal[addr], 1);
	}
	else
	{
		ft_mem(addr / 16, ndigits);
		ft_mem(addr % 16, ndigits);
	}
}

int	ft_printf_mem(void *ptr)
{
	unsigned long int	p;
	int					ndigits;

	ndigits = 0;
	if (ptr == NULL || ptr == 0)
	{
		write(1, "(nil)", 5);
		ndigits += 5;
	}
	else
	{
		p = (unsigned long int) ptr;
		write(1, "0x", 2);
		ft_mem(p, &ndigits);
		ndigits += 2;
	}
	return (ndigits);
}

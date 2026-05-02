/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:12:23 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:09 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_numdigits(unsigned int n)
{
	int		places;

	places = 0;
	if (n == 0)
		places++;
	while (n > 0)
	{
		places++;
		n /= 16;
	}
	return (places);
}

static char	ft_unit_to_hex(unsigned int c, const char x)
{
	int		upper;
	char	*hexadecimal;

	hexadecimal = "0123456789abcdef";
	if (x == 'X')
		upper = -32;
	else
		upper = 0;
	if ((c >= 10) && (c <= 15))
		return (hexadecimal[c] + upper);
	else
		return (hexadecimal[c]);
}

static void	ft_itoh(char **arr, int digits, unsigned int n, const char x)
{
	if (n == 0)
		(*arr)[--digits] = 48;
	while (n > 0)
	{
		(*arr)[digits - 1] = ft_unit_to_hex(n % 16, x);
		n /= 16;
		digits--;
	}
	while (digits > 0)
	{
		(*arr)[digits - 1] = ft_unit_to_hex(15, x);
		digits--;
	}
}

static void	ft_puthex(char *hex)
{
	int	pos;

	pos = 0;
	while (hex[pos] != 0)
	{
		write(1, &hex[pos], 1);
		pos++;
	}
}

int	ft_printf_hex(unsigned int n, const char x)
{
	int		numdigits;
	int		ndigits_ret;
	char	*arr;

	numdigits = ft_numdigits(n);
	ndigits_ret = numdigits;
	arr = (char *) malloc((numdigits + 1) * sizeof(char));
	if (!arr)
		return (ndigits_ret);
	arr[numdigits] = 0;
	ft_itoh(&arr, numdigits, n, x);
	ft_puthex(arr);
	free(arr);
	return (ndigits_ret);
}

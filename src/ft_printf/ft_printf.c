/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:45:18 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:23 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_arg(char s, va_list *ap_copy)
{
	int	arg_size;

	arg_size = 0;
	if (s == 'd' || s == 'i')
		arg_size = ft_printf_int(va_arg(*ap_copy, int));
	else if (s == 'c')
		arg_size = ft_printf_char(va_arg(*ap_copy, int));
	else if (s == 's')
		arg_size = ft_printf_str(va_arg(*ap_copy, const char *));
	else if (s == '%')
		arg_size = ft_printf_pct();
	else if (s == 'x' || s == 'X')
		arg_size = ft_printf_hex(va_arg(*ap_copy, unsigned long int), s);
	else if (s == 'p')
		arg_size = ft_printf_mem(va_arg(*ap_copy, void *));
	else if (s == 'u')
		arg_size = ft_printf_uint(va_arg(*ap_copy, unsigned int));
	return (arg_size);
}

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		char_cnt;

	count = 0;
	char_cnt = 0;
	va_start(ap, s);
	while (s[count] != 0)
	{
		if (s[count] != '%')
			char_cnt += ft_putchar(s[count++]);
		else
		{
			char_cnt += ft_printf_arg(s[++count], &ap);
			count++;
		}
	}
	va_end(ap);
	return (char_cnt);
}

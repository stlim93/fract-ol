/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:45:57 by stelim            #+#    #+#             */
/*   Updated: 2025/12/21 17:28:05 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf_int(int i);
int	ft_printf_char(unsigned char c);
int	ft_printf_str(const char *s);
int	ft_printf_pct(void);
int	ft_printf_hex(unsigned int n, const char x);
int	ft_printf_mem(void *ptr);
int	ft_printf_uint(unsigned int ui);
int	ft_printf(const char *s, ...);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:23:29 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	pos;

	pos = 0;
	if (dest < src)
	{
		while (pos < n)
		{
			*(unsigned char *)(dest + pos) = *(unsigned char *)(src + pos);
			pos++;
		}
	}
	else if (dest > src)
	{
		while (n > 0)
		{
			*(unsigned char *)(dest + n - 1) = *(unsigned char *)(src + n - 1);
			n--;
		}
	}
	return ((void *)dest);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char x[] = "Hello World";
// 	// char y[] = "543      ";
// 	char *y = x + 1;

// 	printf("1. %p: %s\n", x, (unsigned char *)x);
// 	printf("1. %p: %s\n", y, (unsigned char *)y);
// 	// ft_memmove(y, x, 10);
// 	memmove(y, x, 10);
// 	printf("2. %p: %s\n", x, (unsigned char *)x);
// 	printf("2. %p: %s\n", y, (unsigned char *)y);
// }
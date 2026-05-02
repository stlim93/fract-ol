/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:25:42 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			pos;
	unsigned char	*dest_c;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	pos = 0;
	dest_c = (unsigned char *)dest;
	while (pos < n)
	{
		dest_c[pos] = ((unsigned char *)src)[pos];
		pos++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
// 	char x[] = "Hello World";
// 	// char y[] = "543      ";
// 	char *y = x + 3;

// 	printf("1. %p: %s\n", x, (unsigned char *)x);
// 	printf("1. %p: %s\n", y, (unsigned char *)y);
// 	ft_memcpy(y, x, 3);
// 	// memcpy(y, x, 3);
// 	printf("2. %p: %s\n", x, (unsigned char *)x);
// 	printf("2. %p: %s\n", y, (unsigned char *)y);
// }
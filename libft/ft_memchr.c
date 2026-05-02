/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:25:26 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (*(unsigned char *)(s + pos) == (unsigned char)c)
			return ((void *)(s + pos));
		pos++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "123";
//     char c = '2';

//     int x;
//     x = 0;
//     while (x < 6)
//     {
//         printf("1. %p: %c\n", &s[x], ((char *)s)[x]);
//         x++;
//     }
//     printf("2. %p\n", ft_memchr(s, c+256, 10));
//     printf("3. %p\n", memchr(s, c+256, 10));
// 	printf("4. %c %c\n", c, c+255);
// }
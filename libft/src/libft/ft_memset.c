/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:25:51 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		((unsigned char *)s)[pos] = c;
		pos++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "aaaaaaaaaa";

//     printf("1. %p: %s\n", s, (unsigned char *)s);
//     // ft_memset(s, 'o', 7);
// 	memset(s, 'o', 7);
// 	printf("2. %p: %s\n", s, (unsigned char *)s);
// }
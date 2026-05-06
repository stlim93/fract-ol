/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:24:40 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		((unsigned char *)s)[pos] = 0;
		pos++;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "222222222222222";
//     printf("%p: %s\n", s, s);
//     bzero(s, 10);
//     int x = 0;

//     while (x < 16)
//     {
//         printf("%p: %c\n", &s[x], s[x]);
//         x++;
//     }
// }
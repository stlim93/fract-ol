/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:25:37 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	pos;
	int		s1_value;
	int		s2_value;

	pos = 0;
	while (pos < n)
	{
		s1_value = *(unsigned char *)(s1 + pos);
		s2_value = *(unsigned char *)(s2 + pos);
		if (s1_value != s2_value)
			return (s1_value - s2_value);
		pos++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     const void *s1 = "1 2 3 4";
//     const void *s2 = "1  2 3 4";

//     int z = ft_memcmp(s1, s2, 7);
//     printf("%d\n", z);
//     printf("%d\n", memcmp(s1, s2, 7));
// }
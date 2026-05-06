/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:22:51 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((*s == '\0') & (c == '\0'))
		ptr = (char *)s;
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     int pos;
//     const char str[] = "A is an E. A is not a B. A E A A A";
//     char c = 'E';
//     char *ptr = ft_strrchr(str, c);

//     pos = 0;
//     while (str[pos] != '\0')
//     {
//         if (str[pos] == c)
//             printf("1. %p: %c\n", &str[pos], str[pos]);
//         pos++;
//     }
//     printf("2. %p: %c\n", ptr, *ptr);

//     printf("3. %p: %c\n", strrchr(str, c), c);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:25:55 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((*s == '\0') && ((unsigned char)c == '\0'))
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s1[] = "A string of words.";
// 	char c = 'i';

// 	printf("%p: %s\n", ft_strchr(s1, c+256), ft_strchr(s1, c+256));
// 	printf("%p: %s\n", strchr(s1, c), strchr(s1, c));
// }

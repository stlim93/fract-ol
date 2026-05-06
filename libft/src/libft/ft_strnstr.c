/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:21:10 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *string, const char *key, size_t len)
{
	size_t	x;
	size_t	y;
	char	*str;

	x = 0;
	if ((len == 0) && (*key != '\0'))
		return (NULL);
	else if (*key == '\0')
		return ((char *)string);
	while ((string[x] != '\0') & (x < len))
	{
		y = 0;
		if (string[x + y] == key[y])
			str = (char *)&string[x + y];
		while ((string[x + y] == key[y]) & (key[y] != '\0') & (x + y < len))
			y++;
		if (key[y] == '\0')
			return (str);
		x++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char string[] = "This is a string with keyword.";
// 	char keyword[] = "";

// 	printf("%s\n", ft_strnstr(string, keyword, 15));
// 	printf("%s\n", strnstr(string, keyword, 15));
// }
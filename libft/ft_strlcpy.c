/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:26:29 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	total_len;

	total_len = ft_strlen(src);
	if (size != 0)
	{
		while ((size > 1) & (*src != '\0'))
		{
			*dst++ = *src++;
			size--;
		}
		*dst = '\0';
	}
	return (total_len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char dest[] = "Empty string";
// 	char src[] = "To be copied";
// 	int len = 13;

// 	printf("%s\n", dest);
// 	ft_strlcpy(dest, src, len);
// 	// strlcpy(dest, src, len);
// 	printf("%s\n", dest);
// }
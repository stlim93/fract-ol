/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:26:14 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total_len;
	int		pos;

	total_len = 0;
	pos = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while ((*dst != '\0') && (size > 0))
	{
		dst++;
		size--;
		total_len++;
	}
	while ((size > 1) && (src[pos] != '\0'))
	{
		*dst = src[pos++];
		dst++;
		size--;
	}
	*dst = '\0';
	total_len += ft_strlen(src);
	return (total_len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char dest[] = "String";
// 	char src[] = "OK OR NOT";
// 	int len = 3;
// 	int ret = 0;

// 	printf("1. Dest: %s\n   Src: %s\n", dest, src);
// 	printf("2. Dest: %d\n   Src: %d\n", ft_strlen(dest), ft_strlen(src));
// 	ret = ft_strlcat(dest, src, len);
// 	printf("3. Dest: %s\n   Length: %d\n", dest, ret);
// 	printf("4. Dest: %s\n", dest);

// 	char dest2[16] = "String";
// 	char src2[] = "OK OR NOT";
// 	// strlcat(dest2, src2, len);
// 	printf("5. Dest: %s\n   Length: %lu\n", dest2, strlcat(dest2, src2, len));
// }
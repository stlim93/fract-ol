/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:24:45 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if ((nmemb == 0) || (size == 0))
	{
		ptr = (void *) malloc(1);
		return (ptr);
	}
	else if ((size != 0) && (nmemb < (size_t) -1 / size))
	{
		ptr = (void *)malloc(nmemb * size);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
		return (ptr);
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	/* Try either nmemb or size == 0 */
//     void *s = ft_calloc(10, 10);
//     printf("%p: %d, %s\n", s, *(int *)s, (char *)s);
// }
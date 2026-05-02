/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:26:08 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	pos;
	char	*newstring;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc((total_len + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	pos = 0;
	while (*s1 != '\0')
		newstring[pos++] = *s1++;
	while (*s2 != '\0')
		newstring[pos++] = *s2++;
	newstring[pos] = 0;
	return (newstring);
}

// #include <stdio.h>
// int main(void)
// {
//     char s1[] = "This is";
//     char s2[] = " a string.";
//     char *s3 = ft_strjoin(s1, s2);
//     printf("1. %p: %s\n", s1, s1);
//     printf("2. %p: %s\n", s2, s2);
//     printf("3. %p: %s\n", s3, s3);
// }
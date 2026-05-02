/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:25:03 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		pos;
	char	*string;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		string[pos] = (*f)(pos, s[pos]);
		pos++;
	}
	string[pos] = 0;
	return (string);
}

// char ft_shift(unsigned int x, char c)
// {
// 	return(c + x % 2);
// }

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "all lower caps";
// 	char (*fptr)(unsigned int, char) = &ft_shift;
// 	char *t = ft_strmapi(s, fptr);
// 	printf("%p: %s\n", &s, s);
// 	printf("%p: %s\n", &t, t);
// 	free(t);
// }

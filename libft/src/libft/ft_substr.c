/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:23:55 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	pos;
	char	*substring;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len == 0)
		return (ft_strdup(""));
	else if ((start > s_len) || (len == 0))
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	pos = 0;
	while (len > 0)
	{
		substring[pos] = s[start + pos];
		pos++;
		len--;
	}
	substring[pos] = 0;
	return (substring);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *s = NULL;
// 	printf("%s\n", ft_substr(s, 0, 12));
// }
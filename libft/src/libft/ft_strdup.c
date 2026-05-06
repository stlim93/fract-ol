/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:26:02 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		pos;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		newstr[pos] = s[pos];
		pos++;
	}
	newstr[pos] = '\0';
	return (newstr);
}

// #include <stdio.h>
// int main(void)
// {
// 	const char	str[] = "Strings to be copied";
// 	char		*newStr;
// 	newStr = ft_strdup(str);

// 	printf("%p: %s\n", &str, str);
// 	printf("%p: %s\n", &newStr, newStr);
// 	free(newStr);
// }
// // vagrind check for leak
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:50:45 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:43:59 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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

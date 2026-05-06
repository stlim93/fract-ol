/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:31:41 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_numsplits(char const *s, char c)
{
	int	x;

	x = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			x++;
		while ((*s != c) && *s)
			s++;
	}
	return (x);
}

static void	ft_fill_char(char **arr, char const *s, char const *e)
{
	int	nletters;
	int	idx;

	idx = 0;
	nletters = e - s + 1;
	*arr = (char *)malloc(nletters * sizeof(char));
	if (!*arr)
		free(*arr);
	else
	{
		if (s == e)
			(*arr)[nletters] = '\0';
		while (s < e)
		{
			(*arr)[idx] = *s;
			idx++;
			s++;
		}
		(*arr)[idx] = 0;
	}
}

static char	**ft_check_null(char const *s, char ***arr)
{
	if (*s == 0)
		*arr[0] = NULL;
	return (*arr);
}

static void	ft_fill_word(char **arr, char **aptr, char **bptr, char c)
{
	while (**aptr == c)
		*aptr += 1;
	if (ft_strchr(*aptr, c) == NULL)
		*bptr = ft_strchr(*aptr, '\0');
	else
		*bptr = ft_strchr(*aptr, c);
	ft_fill_char(&arr[0], *aptr, *bptr);
	*aptr = *bptr;
	while (**aptr == c)
		*aptr += 1;
	*bptr = *aptr;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		numsplits;
	int		ctr;
	char	*aptr;
	char	*bptr;

	if (!s)
		return (NULL);
	numsplits = ft_numsplits(s, c) + 1;
	arr = (char **)malloc(numsplits * sizeof(char *));
	if (!arr)
		return (NULL);
	aptr = (char *)s;
	ctr = 0;
	ft_check_null(s, &arr);
	while (ctr < numsplits - 1)
	{
		bptr = aptr;
		ft_fill_word(&(arr[ctr]), &aptr, &bptr, c);
		ctr++;
	}
	arr[ctr] = NULL;
	return (arr);
}

// int ft_getptr_size(char **ptr)
// {
// 	int	x;

// 	x = 0;
// 	while (*ptr !=NULL)
// 	{
// 		x++;
// 		ptr++;
// 	}
// 	return (x);
// }

// #include <stdio.h>

// int main(void)
// {
// 	const char	*s = "  tripouille  42  ";
// 	char	c = ' ';
// 	// char 	carr[2] = {c, 0};
// 	// char	*d = " ";
// 	int	x;
// 	int	pos;
// 	printf("%c\n", c);
// 	char	**arr = ft_split(s, c);

// 	printf("Num splits: %d\n", ft_numsplits(s,c));

// 	pos = 0;
// 	x = ft_getptr_size(arr);
// 	printf("%d %d\n", pos, x);
// 	while (pos < x)
// 	{
// 		printf("%d of %d at %p: %s\n", pos+1, x, arr[pos], arr[pos]);
// 		if (arr[pos] == NULL)
// 			printf("Is NULL");
// 		pos++;
// 	}
// 	pos = 0;
// 	while (pos < x)
// 	{
// 		free(arr[pos]);
// 		pos++;
// 	}
// 	free(arr[pos]);
// 	free(arr);
// }

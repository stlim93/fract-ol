/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:31:26 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		pos;

	if (!s || !f)
		return ;
	pos = 0;
	while (s[pos] != '\0')
	{
		(*f)(pos, &s[pos]);
		pos++;
	}
}

// void ft_shift(unsigned int x, char *c)
// {
// 	*c += x;
// }

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "all lower caps";
// 	void (*fptr)(unsigned int, char *) = &ft_shift;
// 	printf("%p: %s\n", &s, s);
// 	ft_striteri(s, fptr);
// 	printf("%p: %s\n", &s, s);
// }

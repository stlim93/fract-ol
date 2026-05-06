/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:48:12 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_digitplaces(int n)
{
	int	places;

	places = 1;
	if (n < 0)
	{
		places += 1;
		if (n < -9)
			places += ft_digitplaces(-(n / 10));
	}
	while (n > 9)
	{
		places++;
		n /= 10;
	}
	return (places);
}

char	*ft_itoa(int n)
{
	int		places;
	int		sign;
	char	*nbr;

	places = ft_digitplaces(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	nbr = (char *)malloc((places + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[places] = '\0';
	if (sign == -1)
		nbr[0] = '-';
	while (places > -sign)
	{
		if (places - 1 >= 0)
			nbr[places - 1] = sign * (n % 10) + '0';
		n = n / 10;
		places--;
	}
	return (nbr);
}
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 		return (0);
// 	else
// 	{
// 		int x = ft_atoi(argv[1]);
// 		char *nbr = ft_itoa(x);
// 		// while (x<5)
// 		// {
// 		// 	printf("%c", nbr[x]);
// 		// 	x++;
// 		// }
// 		printf("%s\n", nbr);
// 		free(nbr);
// 	}
// }
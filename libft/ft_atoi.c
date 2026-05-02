/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:24:27 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:19 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_skippable(const char *nptr)
{
	if ((*nptr >= 9) && (*nptr <= 13))
		return (1);
	else if (*nptr == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_skippable(nptr))
		nptr++;
	if (*nptr == 43)
		nptr++;
	else if (*nptr == 45)
	{
		sign *= -1;
		nptr++;
	}
	while ((*nptr != '\0') && ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (sign * result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
//     char *x;
//     x = argv[argc-1];

//     printf("%d\n", atoi(x));
//     printf("%d\n", ft_atoi(x));
// }

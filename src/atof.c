/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:20:19 by stelim            #+#    #+#             */
/*   Updated: 2026/05/01 16:25:26 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/main.h"
#include <stdio.h>

static	double	ft_integer_part(char *s)
{
	double	result;
	int		pos;

	result = 0;
	pos = 0;
	while (s[pos] != '.' && s[pos])
	{
		if (!(s[pos] >= '0' && s[pos] <= '9'))
		{
			perror("Input error: Not double format");
			exit(EXIT_FAILURE);
		}
		result = result * 10 + s[pos] - '0';
		pos ++;
	}
	return (result);
}

static double	ft_decimal_part(char *s)
{
	double	result;
	int		pos;
	int		dec;

	result = 0;
	pos = 0;
	dec = 10;
	while (s[pos] != '.')
		pos++;
	pos++;
	while (s[pos])
	{
		result = result + ((double)(s[pos] - '0')) / dec;
		pos++;
		dec *= 10;
	}
	return (result);
}

double	ft_atof(char *s)
{
	double	result;
	double	sign;
	int		pos;

	result = 0;
	sign = 1;
	pos = 0;
	if (s[pos] == '-')
	{
		sign *= -1;
		pos++;
	}
	if (s[pos] == '+')
		pos++;
	if (!(s[pos] >= '0' && s[pos] <= '9'))
	{
		perror("Input error: Not double format");
		exit(1);
	}
	result = ft_integer_part(&(s[pos])) + ft_decimal_part(&(s[pos]));
	return (result * sign);
}

int	main(int argc, char *argv[])
{
	printf("%f\n", ft_atof(argv[1]));
}

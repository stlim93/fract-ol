/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:20:19 by stelim            #+#    #+#             */
/*   Updated: 2026/05/07 20:15:33 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_output_error(void)
{
	write(2, "Input error: Not double format\n", 31);
	exit(EXIT_FAILURE);
}

static	double	ft_integer_part(char *s)
{
	double	result;
	int		pos;

	result = 0;
	pos = 0;
	while (s[pos] != '.' && s[pos] != '\0')
	{
		if (!(s[pos] >= '0' && s[pos] <= '9'))
			ft_output_error();
		result = result * 10 + s[pos] - '0';
		if (result < INT_MIN || result > INT_MAX)
			ft_output_error();
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
		if (!(s[pos] >= '0' && s[pos] <= '9'))
			ft_output_error();
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
		ft_output_error();
	result = ft_integer_part(&(s[pos]));
	printf("asd");
	if (ft_strchr(s, '.') != NULL)
		result += ft_decimal_part(&(s[pos]));
	return (result * sign);
}

// int	main(int argc, char *argv[])
// {
// 	printf("%.6lf\n", ft_atof(argv[1]));
// }

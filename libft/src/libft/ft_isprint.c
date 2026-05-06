/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:32:07 by stelim            #+#    #+#             */
/*   Updated: 2025/11/29 22:32:07 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
// 	for(int i=0; i< 257; i++)
// 	{
// 		if (ft_isprint(i) != isprint(i))
// 		{
// 		printf("%d: ft_isprint: %d\n", i+1, ft_isprint(i));
// 		printf("%d: isprint: %d\n", i+1, isprint(i));
// 		}
// 	}
// }
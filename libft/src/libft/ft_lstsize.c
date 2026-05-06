/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:53:50 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*list;
// 	t_list	*list2;
// 	t_list	*list3;
// 	char 	*s1 = "First String";
// 	char	*s2 = "Second String";
// 	char	*s3 = "Third String";

// 	list = ft_lstnew((void *) s1);
// 	list2 = ft_lstnew((void *) s2);
// 	list3 = ft_lstnew((void *) s3);
// 	ft_lstadd_front(&list, list2);
// 	ft_lstadd_front(&list2, list3);

// 	printf("%s\n", (char *) list3->content);
// 	printf("%s\n", (char *) list3->next->content);
// 	printf("%s\n", (char *) list3->next->next->content);
// 	printf("Total length: %d\n", ft_lstsize(list3));
// }
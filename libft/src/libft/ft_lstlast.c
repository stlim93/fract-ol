/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:08:08 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		size;
	int		ctr;
	t_list	*last;

	size = ft_lstsize(lst);
	ctr = 1;
	last = lst;
	while (ctr < size)
	{
		last = last->next;
		ctr++;
	}
	return (last);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*list;
// 	t_list	*list2;
// 	t_list	*list3;
// 	t_list	*last;
// 	char 	*s1 = "First String";
// 	char	*s2 = "Second String";
// 	char	*s3 = "Third String";

// 	list = ft_lstnew((void *) s1);
// 	list2 = ft_lstnew((void *) s2);
// 	list3 = ft_lstnew((void *) s3);
// 	ft_lstadd_front(&list, list2);
// 	ft_lstadd_front(&list2, list3);

// 	last = ft_lstlast(list3);

// 	printf("%p: %s\n", list3, (char *) list3->content);
// 	printf("%p: %s\n", list3->next, (char *) list3->next->content);
// 	printf("%p: %s\n", list3->next->next, (char *) list3->next->next->content);
// 	printf("Total length: %d\n", ft_lstsize(list3));
// 	printf("Last string is: %s at %p\n", (char *) last->content, last);
// }
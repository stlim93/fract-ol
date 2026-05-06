/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:59:03 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// void	to_upper(void *ptr)
// {
// 	printf("%p: %c to ", ptr, *(char*)ptr);
// 	*(char *)ptr -= 32;
// 	printf("%c\n", *(char *)ptr);
// 	printf("%p: %c\n", ptr, *(char*)ptr);
// }

// int		main(void)
// {
// 	char s1[] = "a";
// 	char s2[] = "b";
// 	char s3[] = "c";
// 	char s4[] = "d";

// 	t_list *t1 = ft_lstnew(s1);
// 	t_list *t2 = ft_lstnew(s2);
// 	t_list *t3 = ft_lstnew(s3);
// 	t_list *t4 = ft_lstnew(s4);

// 	ft_lstadd_back(&t3, t4);
// 	ft_lstadd_back(&t2, t3);
// 	ft_lstadd_back(&t1, t2);

// 	ft_lstiter(t1, &to_upper);

// 	while (t1)
// 	{
// 		printf("%s\n", (char *)t1->content);
// 		t1 = t1->next;
// 	}
// }
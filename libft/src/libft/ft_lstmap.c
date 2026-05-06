/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:38:51 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!f || !del || !lst)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

// #include <stdio.h>
// void	*to_upper(void *ptr)
// {
// 	char	*ptr2 = NULL;
// 	*ptr2 = *(char *)ptr - 32;
// 	return ((void *)ptr2);
// }

// void	del(void *ptr)
// {
// 	free(ptr);
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
// 	t_list *t5 = NULL;

// 	ft_lstadd_back(&t3, t4);
// 	ft_lstadd_back(&t2, t3);
// 	ft_lstadd_back(&t1, t2);

// 	t5 = ft_lstmap(t1, &to_upper, &del);

// 	while (t5)
// 	{
// 		printf("%s\n", (char *)t5->content);
// 		t5 = t5->next;
// 	}
// }
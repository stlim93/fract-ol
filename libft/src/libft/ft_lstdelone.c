/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:15:40 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:42:35 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if ((lst == NULL) || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// void	del(void *ptr)
// {
// 	printf("1. ASD: %s\n", (char *)ptr);
// 	printf("2. ASD\n");
// }

// int main(void)
// {
// 	t_list	*list;
// 	t_list	*list2;
// 	t_list	*list3;
// 	// char 	*s1 = "First String";
// 	// char	*s2 = "Second String";
// 	// char	*s3 = "Third String";
// 	void	(*fptr)(void *) = &del;

// 	list = ft_lstnew("First String");
// 	list2 = ft_lstnew("Second String");
// 	list3 = ft_lstnew("Third String");
// 	ft_lstadd_back(&list, list2);
// 	ft_lstadd_back(&list2, list3);

// 	printf("%s\n", (char *) list->content);
// 	printf("%s\n", (char *) list->next->content);
// 	printf("%s\n", (char *) list->next->next->content);

// 	ft_lstdelone(list, fptr);

// 	printf("%s\n", (char *) list2->content);
// 	printf("%s\n", (char *) list2->next->content);
// 	free(list2);
// 	free(list3);
// }
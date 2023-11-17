/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/17 19:05:21 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

t_list	*one_node(int num);

void	print_list(t_list *list)
{
	t_list	*node;

	node = list;
	while (node)
	{
		printf("{ %d } -> ", *(int *) node->content);
		node = node->next;
	}
	printf("{ NULL }\n");
}

void	free_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;

	list = one_node(42);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

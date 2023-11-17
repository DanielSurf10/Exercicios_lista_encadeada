/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/17 00:09:25 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

t_list	*add_front_range(int min, int max);

void	print_list(t_list *list)
{
	t_list	*node;

	node = list;
	while (node)
	{
		printf("{ %d } -> ", *(int *)node->content);
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

	list = add_front_range(1, 3);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

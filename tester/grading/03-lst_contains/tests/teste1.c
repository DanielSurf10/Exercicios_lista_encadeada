/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/18 20:31:42 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

int	lst_contains(t_list *lst, int num);

t_list	*add_front_range(int min, int max)
{
	int		i;
	int		size;
	int		*num;
	t_list	*list;
	t_list	*node;

	i = max;
	list = NULL;
	size = max - min;
	if (size <= 0)
		size = -size;
	while (size >= 0)
	{
		num = malloc(sizeof(int));
		*num = i;
		node = ft_lstnew(num);
		ft_lstadd_front(&list, node);
		if (min < max)
			i--;
		else
			i++;
		size--;
	}
	return (list);
}

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
	int		teste;
	t_list	*list;

	teste = 0;
	list = add_front_range(0, 0);
	printf("lst_contains(%d) = %d = ", teste, lst_contains(list, teste));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

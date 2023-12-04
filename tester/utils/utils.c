/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:28:35 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	_print_list(t_list *list)
{
	t_list	*node;

	node = list;
	while (node)
	{
		if (node->content)
			printf("{ (%d) } -> ", *(int *)node->content);
		else
			printf("{ NULL } -> ");
		node = node->next;
	}
	printf("NULL\n");
}

void	_free_content(void *content)
{
	free(content);
}

t_list	*_populate_lst(int min, int max)
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

t_list	*_create_node(int num)
{
	int		*allocated;
	t_list	*list;

	allocated = (int *) malloc(sizeof(int));
	if (!allocated)
		return (NULL);
	*allocated = num;
	list = ft_lstnew(allocated);
	if (!list)
	{
		free(allocated);
		allocated = NULL;
		return (NULL);
	}
	return (list);
}

void	_set_index(t_list *list)
{
	(void)list;
// 	int		i;
// 	t_list	*node;
//
// 	i = 0;
// 	node = list;
// 	while (node)
// 	{
// 		node->index = i;
// 		node = node->next;
// 		i++;
// 	}
}

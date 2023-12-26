/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sum_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:53:55 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/26 01:50:26 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	put_in_pointers(t_list *node1, t_list *node2,
		t_list **node_one, t_list **node_two)
{
	*node_one = node1;
	*node_two = node2;
}

static int	get_content(t_list *lst)
{
	return (*((int *) lst->content));
}

static int	get_sum(t_list *node1, t_list *node2)
{
	int	sum;

	sum = get_content(node1);
	sum += get_content(node2);
	return (sum);
}

int	lst_sum_pair(t_list *lst, int sum_value, t_list **node_one,
			t_list **node_two)
{
	int		sum;
	t_list	*front_node;
	t_list	*iter_node;

	front_node = lst;
	while (front_node)
	{
		iter_node = front_node->next;
		while (iter_node)
		{
			if (front_node->content && iter_node->content)
			{
				sum = get_sum(front_node, iter_node);
				if (sum_value == sum)
				{
					put_in_pointers(front_node, iter_node, node_one, node_two);
					return (1);
				}
			}
			iter_node = iter_node->next;
		}
		front_node = front_node->next;
	}
	put_in_pointers(NULL, NULL, node_one, node_two);
	return (0);
}

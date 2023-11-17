/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:08:47 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/17 19:26:48 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*two_nodes(int num1, int num2)
{
	int		*alloc_num1;
	int		*alloc_num2;
	t_list	*node1;
	t_list	*node2;

	alloc_num1 = (int *) malloc(sizeof(int));
	*alloc_num1 = num1;
	alloc_num2 = (int *) malloc(sizeof(int));
	*alloc_num2 = num2;
	node1 = ft_lstnew(alloc_num1);
	node2 = ft_lstnew(alloc_num2);
	node1->next = node2;
	return (node1);
}

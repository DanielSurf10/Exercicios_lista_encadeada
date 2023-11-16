/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/16 20:22:03 by danbarbo         ###   ########.fr       */
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
		printf("%d\n", *(int *)node->content);
		node = node->next;
	}
}

int	main(void)
{
	t_list	*list;

	list = add_front_range(1, 10);
	print_list(list);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:12:15 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/17 00:40:28 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

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

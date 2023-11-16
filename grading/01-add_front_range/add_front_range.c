/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:12:15 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/16 20:20:21 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*add_front_range(int min, int max)
{
	t_list	*list;
	t_list	*node;
	int		i;
	int		*num;

	list = NULL;
	i = min;
	while (i <= max)
	{
		num = malloc(sizeof(int));
		node = ft_lstnew(num);
		ft_lstadd_front(&list, node);
		i++;
	}
	return (list);
}

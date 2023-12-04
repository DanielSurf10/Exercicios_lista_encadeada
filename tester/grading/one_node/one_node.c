/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:49 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/17 19:00:26 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*one_node(int num)
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

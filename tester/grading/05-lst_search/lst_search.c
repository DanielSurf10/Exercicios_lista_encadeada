/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:11:50 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 22:13:16 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*lst_search(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->content && *((int *) lst->content) == num)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

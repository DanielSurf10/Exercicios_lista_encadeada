/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:00:33 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:42:02 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	lst_contains(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->content && *((int *) lst->content) == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:00:33 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/18 20:09:40 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	lst_contains(t_list *lst, int num)
{
	while (lst)
	{
		if (*((int *) lst->content) == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

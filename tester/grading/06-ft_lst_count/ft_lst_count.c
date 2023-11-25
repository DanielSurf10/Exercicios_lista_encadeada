/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:03:12 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 17:56:00 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lst_count(t_list *lst, int num)
{
	int		count;
	t_list	*aux;

	count = 0;
	aux = lst;
	while (aux)
	{
		if (aux->content && *((int *) (aux->content)) == num)
			count++;
		aux = aux->next;
	}
	return (count);
}

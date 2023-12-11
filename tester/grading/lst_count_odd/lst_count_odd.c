/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count_odd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:02:49 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/11 23:10:25 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	lst_count_odd(t_list *lst)
{
	int		num;
	int		odd_count;
	t_list	*aux;

	odd_count = 0;
	aux = lst;
	while (aux)
	{
		if (aux->content)
		{
			num = *((int *) aux->content);
			if (num % 2 != 0)
				odd_count += 1;
		}
		aux = aux->next;
	}
	return (odd_count);
}

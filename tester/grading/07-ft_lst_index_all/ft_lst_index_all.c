/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_index_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:13:20 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/27 01:50:00 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lst_index_all(t_list *lst, int num)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		if (aux->content && *((int *) (aux->content)) == num)
			break ;
		aux = aux->next;
	}
	return (i);
}

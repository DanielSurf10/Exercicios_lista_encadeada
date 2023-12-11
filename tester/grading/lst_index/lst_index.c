/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:54:59 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/11 22:17:02 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*lst_index(t_list *lst, int index)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	if (index < 0)
		return (NULL);
	while (aux && i < index)
	{
		aux = aux->next;
		i++;
	}
	return (aux);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:39:13 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/06 22:44:00 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*third_node(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = lst;
	while (aux && i < 3)
	{
		aux = aux->next;
		i++;
	}
	return (aux);
}

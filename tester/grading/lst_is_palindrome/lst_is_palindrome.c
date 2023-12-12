/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_is_palindrome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:33:14 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/12 04:21:08 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static t_list	*lst_index(t_list *lst, int index)
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

int	lst_is_palindrome(t_list *lst)
{
	int		num[2];
	int		back_node_index;
	t_list	*aux;

	if (!lst || ft_lstsize(lst) == 1)
		return (1);
	back_node_index = ft_lstsize(lst) - 1;
	aux = lst;
	num[0] = *((int *) aux->content);
	num[1] = *((int *) lst_index(lst, back_node_index)->content);
	while (aux && num[0] == num[1])
	{
		num[0] = *((int *) aux->content);
		num[1] = *((int *) lst_index(lst, back_node_index)->content);
		back_node_index -= 1;
		aux = aux->next;
	}
	if (!aux)
		return (1);
	return (0);
}

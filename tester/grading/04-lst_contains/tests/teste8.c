/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:52:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	lst_contains(t_list *lst, int num);

void	ft_lstclear_cont(t_list **lst, void (*del)(void*))
{
	t_list	*aux1;
	t_list	*aux2;

	if (lst)
	{
		aux1 = *lst;
		while (aux1)
		{
			aux2 = aux1->next;
			del(aux1->content);
			aux1->content = NULL;
			aux1 = aux2;
		}
	}
}

int	main(void)
{
	int		teste = 5;
	t_list	*list;

	list = populate_lst(0, 10);
	ft_lstclear_cont(&list, &free_content);
	printf("lst_contains(%d) = %d => list = ", teste, lst_contains(list, teste));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

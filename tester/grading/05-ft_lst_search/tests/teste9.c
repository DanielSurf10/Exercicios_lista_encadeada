/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:51:31 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lst_search(t_list *lst, int num);

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
	int		teste;
	t_list	*found;
	t_list	*list;

	teste = 1;
	list = populate_lst(0, 5);
	ft_lstclear_cont(&list, &free_content);
	found = ft_lst_search(list, teste);
	if (found)
		printf("ft_lst_search(list, %d) = %d => list = ", teste, *((int *)(found->content)));
	else
		printf("ft_lst_search(list, %d) = %s => list = ", teste, "( NULL )");
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

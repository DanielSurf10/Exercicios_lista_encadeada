/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 01:12:48 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lst_search(t_list *lst, int num);

int	main(void)
{
	int		teste;
	t_list	*found;
	t_list	*list;

	teste = 15;
	list = populate_lst(0, 10);
	found = ft_lst_search(list, teste);
	if (found)
		printf("ft_lst_search(list, %d) = %d => list = ", teste, *((int *)(found->content)));
	else
		printf("ft_lst_search(list, %d) = %s => list = ", teste, "( NULL )");
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:24:58 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	lst_contains(t_list *lst, int num);

int	main(void)
{
	int		teste = 7;
	t_list	*list;

	list = populate_lst(0, 10);
	printf("lst_contains(%d) = %d => list = ", teste, lst_contains(list, teste));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

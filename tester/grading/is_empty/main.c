/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:58 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_empty(t_list *lst);

int	main(int argv, char *argc[])
{
	t_list	*list;
	int		num1;
	int		num2;

	list = NULL;
	if (argv == 3)
	{
		num1 = atoi(argc[1]);
		num2 = atoi(argc[2]);
		list = _populate_lst(num1, num2);
	}
	printf("is_empty(list) = %d => list = ", is_empty(list));
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

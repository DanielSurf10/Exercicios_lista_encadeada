/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:10:36 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/11 23:12:03 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	lst_count_odd(t_list *lst);

int	main(int argc, char *argv[])
{
	int		i = 1;
	t_list	*list = NULL;

	if (argc > 1)
	{
		while (argc - i > 0)
		{
			if (strcmp(argv[i], "NULL") == 0)
				ft_lstadd_back(&list, ft_lstnew(NULL));
			else
				ft_lstadd_back(&list, _create_node(atoi(argv[i])));
			i++;
		}
	}
	printf("ft_lst_count_odd(list) = %d => list = ", lst_count_odd(list));
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

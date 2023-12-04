/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:59:17 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 02:22:55 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	lst_sum(t_list *lst);

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
	printf("lst_sum(list) = %d => list = ", lst_sum(list));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:38:58 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/11 22:23:19 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*lst_index(t_list *lst, int index);

int	main(int argc, char *argv[])
{
	int		test = 0;
	int		i = 2;
	t_list	*list = NULL;
	t_list	*node_found;

	if (argc > 2)	// No argv[1] vai ficar o número a ser testado
	{
		test = atoi(argv[1]);
		while (argc - i > 0)
		{
			if (strcmp(argv[i], "NULL") == 0)
				ft_lstadd_back(&list, ft_lstnew(NULL));
			else
				ft_lstadd_back(&list, _create_node(atoi(argv[i])));
			i++;
		}
	}

	node_found = lst_index(list, test);
	if (node_found)
	{
		if (node_found->content)
			printf("lst_index(list, %d) = (%d) => list = ", test, *((int *) node_found->content));
		else
			printf("lst_index(list, %d) = (NULL) => list = ", test);
	}
	else
		printf("lst_index(list, %d) = NULL => list = ", test);
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

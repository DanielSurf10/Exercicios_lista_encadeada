/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:30:03 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/26 01:13:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	lst_sum_pair(t_list *lst, int sum_value, t_list **node_one,
			t_list **node_two);

int	main(int argc, char *argv[])
{
	int		test = 0;
	int		i = 2;
	int		status = 0;
	t_list	*list = NULL;
	t_list	*node_one;
	t_list	*node_two;

	if (argc > 1)
		test = atoi(argv[1]);
	if (argc > 2)	// No argv[1] vai ficar o número a ser testado
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
	status = lst_sum_pair(list, test, &node_one, &node_two);
	if (status)
		printf("lst_sum_pair(list, %d) = ( (%d), (%d) ) = return = %d => list = ", test, *((int *) node_one->content), *((int *) node_two->content), status);
	else
		printf("lst_sum_pair(list, %d) = ( %p, %p ) = return = %d => list = ", test, node_one, node_two, status);
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:58:39 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:15 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*lst_search(t_list *lst, int num);

int	main(int argc, char *argv[])
{
	int		test = 0;
	int		i = 2;
	int		num_found = 0;
	t_list	*list = NULL;
	t_list	*found;

	if (argc > 1)		// No argv[1] vai ficar o número a ser testado
		test = atoi(argv[1]);
	if (argc > 2)
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
	found = lst_search(list, test);
	num_found = found ? *((int *) found->content) : 0;
	printf("ft_lst_search(list, %d) = ", test);
	if (found)
		printf("%d\n", num_found);
	else
		printf("%s\n", "( NULL )");
	printf("\t\t\t\tlist:\t");
	_print_list(list);
	printf("\t\t\t\tfound:\t");
	_print_list(found);
	ft_lstclear(&list, &_free_content);
	return (0);
}

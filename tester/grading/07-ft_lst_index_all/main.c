/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:08:56 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/27 01:50:09 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_lst_index_all(t_list *lst, int num);

int	main(int argc, char *argv[])
{
	int		test = 0;
	int		i = 2;
	t_list	*list = NULL;

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
	printf("ft_lst_index_all(list, %d) = %d => list = ", test, ft_lst_index_all(list, test));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

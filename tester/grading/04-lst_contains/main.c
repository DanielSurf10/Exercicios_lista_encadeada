/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:08:49 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 15:10:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	lst_contains(t_list *lst, int num);

t_list	*_one_node(int num)
{
	int		*allocated;
	t_list	*list;

	allocated = (int *) malloc(sizeof(int));
	if (!allocated)
		return (NULL);
	*allocated = num;
	list = ft_lstnew(allocated);
	if (!list)
	{
		free(allocated);
		allocated = NULL;
		return (NULL);
	}
	return (list);
}

int	main(int argc, char *argv[])
{
	int		test = 0;
	int		i = 2;
	t_list	*list = NULL;

	if (argc > 2)	// No argv[1] vai ficar o número a ser testado
	{
		test = atoi(argv[1]);
		while (argc - i > 0)
		{
			if (strcmp(argv[i], "NULL") == 0)
				ft_lstadd_back(&list, ft_lstnew(NULL));
			else
				ft_lstadd_back(&list, _one_node(atoi(argv[i])));
			i++;
		}
	}
	printf("lst_contains(list, %d) = %d => list = ", test, lst_contains(list, test));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:58:39 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 16:33:48 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lst_search(t_list *lst, int num);

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
				ft_lstadd_back(&list, _one_node(atoi(argv[i])));
			i++;
		}
	}
	found = ft_lst_search(list, test);
	num_found = found ? *((int *) found->content) : 0;
	printf("ft_lst_search(list, %d) = ", test);
	if (found)
		printf("%d\n", num_found);
	else
		printf("%s\n", "( NULL )");
	printf("\t\t\t\tlist:\t");
	print_list(list);
	printf("\t\t\t\tfound:\t");
	print_list(found);
	ft_lstclear(&list, &free_content);
	return (0);
}

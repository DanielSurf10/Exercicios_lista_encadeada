/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:08:49 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:14 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*first_node(t_list *lst);

int	main(int argc, char *argv[])
{
	int		i = 1;
	t_list	*list = NULL;
	t_list	*aux;

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
	aux = first_node(list);
	if (aux)
	{
		if (aux->content)
			printf("first_node(list) = (%d) => list = ", *((int *)aux->content));
		else
			printf("first_node(list) = (NULL) => list = ");
	}
	else
		printf("first_node(list) = NULL => list = ");
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

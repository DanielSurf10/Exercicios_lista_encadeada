/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:38:58 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/06 22:39:31 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*third_node(t_list *lst);

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
	aux = third_node(list);
	if (aux)
	{
		if (aux->content)
			printf("third_node(list) = (%d) => list = ", *((int *)aux->content));
		else
			printf("third_node(list) = (NULL) => list = ");
	}
	else
		printf("third_node(list) = NULL => list = ");
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

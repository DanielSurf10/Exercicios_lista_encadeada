/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:04:46 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:15 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*one_node(int num);

int	main(int argc, char *argv[])
{
	int		test = 0;
	t_list	*list;

	if (argc == 2)
		test = atoi(argv[1]);
	list = one_node(test);
	printf("one_node(%d) => ", test);
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

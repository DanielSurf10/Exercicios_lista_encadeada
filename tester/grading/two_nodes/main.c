/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:54:23 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:15 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*two_nodes(int num1, int num2);

int main(int argc, char *argv[])
{
	int		test_n1 = 0;
	int		test_n2 = 0;
	t_list	*list;

	if (argc == 3)
	{
		test_n1 = atoi(argv[1]);
		test_n2 = atoi(argv[2]);
	}
	list = two_nodes(test_n1, test_n2);
	printf("two_nodes(%d, %d) => ", test_n1, test_n2);
	_print_list(list);
	ft_lstclear(&list, &_free_content);
	return (0);
}

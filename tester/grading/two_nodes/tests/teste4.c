/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:21:51 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_list	*two_nodes(int num1, int num2);

int	main(void)
{
	int		test_n1 = -10;
	int		test_n2 = -20;
	t_list	*list;

	list = two_nodes(test_n1, test_n2);
	printf("two_nodes(%d, %d) => ", test_n1, test_n2);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

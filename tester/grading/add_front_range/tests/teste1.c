/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:58:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_list	*add_front_range(int min, int max);

int	main(void)
{
	int		test_num1 = 1;
	int		test_num2 = 10;
	t_list	*list;

	list = add_front_range(test_num1, test_num2);
	printf("add_front_range(%d, %d) => ", test_num1, test_num2);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

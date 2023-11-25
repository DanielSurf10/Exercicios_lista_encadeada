/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:46:56 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 16:55:29 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*add_front_range(int min, int max);

int main(int argc, char *argv[])
{
	int		test_num1 = 0;
	int		test_num2 = 0;
	t_list	*list;

	if (argc == 3)
	{
		test_num1 = atoi(argv[1]);
		test_num2 = atoi(argv[2]);
	}
	list = add_front_range(test_num1, test_num2);
	printf("add_front_range(%d, %d) => ", test_num1, test_num2);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:18:55 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_list	*one_node(int num);

int	main(void)
{
	int		test = -2147483648;
	t_list	*list;

	list = one_node(test);
	printf("one_node(%d) => ", test);
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

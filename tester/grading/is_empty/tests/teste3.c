/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:18 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/21 03:13:54 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	is_empty(t_list *lst);

int	main(void)
{
	t_list	*list;

	list = NULL;
	printf("is_empty(list) = %d => list = ", is_empty(list));
	print_list(list);
	ft_lstclear(&list, &free_content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:27:27 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "linked_list.h"
# include <stdio.h>
# include <string.h>

void	_print_list(t_list *list);
void	_free_content(void *content);
t_list	*_populate_lst(int min, int max);
void	_set_index(t_list *list);
t_list	*_create_node(int num);

#endif

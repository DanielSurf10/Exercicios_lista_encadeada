/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:27:27 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/25 14:47:42 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "linked_list.h"
# include <stdio.h>
# include <string.h>

void	print_list(t_list *list);
void	free_content(void *content);
t_list	*populate_lst(int min, int max);
void	set_index(t_list *list);

#endif

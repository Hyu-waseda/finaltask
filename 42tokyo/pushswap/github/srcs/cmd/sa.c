/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:22 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:43:19 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (nil_a->next->next == nil_a)
		return ;
	first = nil_a->next;
	second = nil_a->next->next;
	third = nil_a->next->next->next;
	nil_a->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = nil_a;
	add_cmd(nil_a, nil_b, nil_c, 1);
}

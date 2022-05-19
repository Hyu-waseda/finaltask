/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:51:13 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:43:28 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (nil_a->next->next == nil_a || nil_b->next->next == nil_b)
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
	first = nil_b->next;
	second = nil_b->next->next;
	third = nil_b->next->next->next;
	nil_b->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = nil_b;
	add_cmd(nil_a, nil_b, nil_c, 3);
}

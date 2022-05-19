/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:55:05 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:43:02 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_a->next->next == nil_a || nil_b->next->next == nil_b)
		return ;
	(nil_a->next->next)->prev = nil_a;
	(nil_a->next)->prev = nil_a->prev;
	nil_a->prev = nil_a->next;
	(nil_a->next->prev)->next = nil_a->next;
	nil_a->next = (nil_a->next)->next;
	(nil_a->prev)->next = nil_a;
	(nil_b->next->next)->prev = nil_b;
	(nil_b->next)->prev = nil_b->prev;
	nil_b->prev = nil_b->next;
	(nil_b->next->prev)->next = nil_b->next;
	nil_b->next = (nil_b->next)->next;
	(nil_b->prev)->next = nil_b;
	add_cmd(nil_a, nil_b, nil_c, 8);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:24 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:42:44 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_b == nil_b->next)
		return ;
	(nil_a->next)->prev = nil_b->next;
	(nil_b->next)->prev = nil_a;
	(nil_b->next->next)->prev = nil_b;
	nil_b->next = (nil_b->next)->next;
	(nil_a->next->prev)->next = nil_a->next;
	nil_a->next = (nil_a->next)->prev;
	add_cmd(nil_a, nil_b, nil_c, 4);
	(nil_a->now_size)++;
	(nil_b->now_size)--;
}

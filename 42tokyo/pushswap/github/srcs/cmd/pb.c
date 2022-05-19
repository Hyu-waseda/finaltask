/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:53:01 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:42:49 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_a == nil_a->next)
		return ;
	(nil_b->next)->prev = nil_a->next;
	(nil_a->next)->prev = nil_b;
	(nil_a->next->next)->prev = nil_a;
	nil_a->next = (nil_a->next)->next;
	(nil_b->next->prev)->next = nil_b->next;
	nil_b->next = (nil_b->next)->prev;
	add_cmd(nil_a, nil_b, nil_c, 5);
	(nil_a->now_size)--;
	(nil_b->now_size)++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:55:25 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:43:11 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_b->next->next == nil_b)
		return ;
	nil_b->next->prev = nil_b->prev;
	nil_b->prev = nil_b->prev->prev;
	nil_b->prev->next->prev = nil_b;
	nil_b->prev->next->next = nil_b->next;
	nil_b->next = nil_b->prev->next;
	nil_b->prev->next = nil_b;
	add_cmd(nil_a, nil_b, nil_c, 10);
}

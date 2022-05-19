/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:54:53 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:42:58 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_b->next->next == nil_b)
		return ;
	(nil_b->next->next)->prev = nil_b;
	(nil_b->next)->prev = nil_b->prev;
	nil_b->prev = nil_b->next;
	(nil_b->next->prev)->next = nil_b->next;
	nil_b->next = (nil_b->next)->next;
	(nil_b->prev)->next = nil_b;
	add_cmd(nil_a, nil_b, nil_c, 7);
}

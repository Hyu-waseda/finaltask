/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:54:33 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:42:54 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_a->next->next == nil_a)
		return ;
	(nil_a->next->next)->prev = nil_a;
	(nil_a->next)->prev = nil_a->prev;
	nil_a->prev = nil_a->next;
	(nil_a->next->prev)->next = nil_a->next;
	nil_a->next = (nil_a->next)->next;
	(nil_a->prev)->next = nil_a;
	add_cmd(nil_a, nil_b, nil_c, 6);
}

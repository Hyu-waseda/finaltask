/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:55:17 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:43:07 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_a->next->next == nil_a)
		return ;
	nil_a->next->prev = nil_a->prev;
	nil_a->prev = nil_a->prev->prev;
	nil_a->prev->next->prev = nil_a;
	nil_a->prev->next->next = nil_a->next;
	nil_a->next = nil_a->prev->next;
	nil_a->prev->next = nil_a;
	add_cmd(nil_a, nil_b, nil_c, 9);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:48:51 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 16:46:18 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	should_sorted_rank_exsist(t_list *nil_a, t_list *nil_b);

int	set_sorted(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	i;

	if (nil_a->now_size <= 1)
		return (0);
	i = 0;
	check_sorted(nil_a, nil_b, nil_c);
	while (should_sorted_rank_exsist(nil_a, nil_b))
	{
		i += set_sorted_nil_a(nil_a, nil_b, nil_c);
		set_sorted_nil_b_top(nil_a, nil_b, nil_c);
		set_sorted_nil_b_bottom(nil_a, nil_b, nil_c);
	}
	check_sorted(nil_a, nil_b, nil_c);
	return (i);
}

static int	should_sorted_rank_exsist(t_list *nil_a, t_list *nil_b)
{
	if (nil_a->now_size <= 1)
		return (0);
	if (nil_a->next->rank == nil_a->sorted + 1)
		return (1);
	if (nil_a->now_size - nil_a->sorted >= 2
		&& nil_a->next->next->rank == nil_a->sorted + 1)
		return (1);
	if (nil_a->now_size - nil_a->sorted >= 3
		&& nil_a->next->next->next->rank == nil_a->sorted + 1)
		return (1);
	if (nil_b->now_size >= 1 && nil_b->next->rank == nil_a->sorted + 1)
		return (1);
	if (nil_b->now_size >= 2 && nil_b->next->next->rank == nil_a->sorted + 1)
		return (1);
	if (nil_b->now_size >= 2 && nil_b->prev->rank == nil_a->sorted + 1)
		return (1);
	if (nil_b->now_size >= 3 && nil_b->prev->prev->rank == nil_a->sorted + 1)
		return (1);
	if (nil_b->now_size >= 4
		&& nil_b->prev->prev->prev->rank == nil_a->sorted + 1)
		return (1);
	return (0);
}

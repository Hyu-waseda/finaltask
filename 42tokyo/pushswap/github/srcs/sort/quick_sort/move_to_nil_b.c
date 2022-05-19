/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_nil_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:45:57 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/14 01:24:03 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_nil_b_half(t_list *nil_a, t_list *nil_b
	, t_cmd_list *nil_c, int pivot)
{
	t_list	*p;
	int		is_first_time;

	p = nil_a->next;
	while (p->rank <= pivot)
		p = p->next;
	is_first_time = 1;
	while (p != nil_a->next || is_first_time)
	{
		if (nil_a->next->rank <= pivot)
		{
			pb(nil_a, nil_b, nil_c);
			if (nil_b->next->rank <= pivot / 2)
				rb(nil_a, nil_b, nil_c);
			continue ;
		}
		ra(nil_a, nil_b, nil_c);
		is_first_time = 0;
	}
}

void	move_to_nil_b_half2(t_list *nil_a, t_list *nil_b
	, t_cmd_list *nil_c, int pivot)
{
	while (nil_a->next->rank != 1)
	{
		if (nil_a->next->rank > pivot)
		{
			pb(nil_a, nil_b, nil_c);
			set_sorted(nil_a, nil_b, nil_c);
			if (nil_b->next->rank <= pivot + pivot / 2)
				rb(nil_a, nil_b, nil_c);
			set_sorted(nil_a, nil_b, nil_c);
			continue ;
		}
		ra(nil_a, nil_b, nil_c);
		set_sorted(nil_a, nil_b, nil_c);
	}
}

void	move_to_nil_b_remaining(t_list *nil_a, t_list *nil_b
	, t_cmd_list *nil_c, int n)
{
	int	i;

	if (n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		n -= set_sorted(nil_a, nil_b, nil_c);
		pb(nil_a, nil_b, nil_c);
		n -= set_sorted(nil_a, nil_b, nil_c);
		if (nil_b->next->rank < nil_b->prev->rank)
			rb(nil_a, nil_b, nil_c);
		n -= set_sorted(nil_a, nil_b, nil_c);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_nil_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:11:01 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 16:48:24 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_to_nil_a_3_or_less_size(t_list *nil_a, t_list *nil_b,
				t_cmd_list *nil_c);
static void	pa_3_times(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
static void	move_to_nil_a_pivot_or_more(t_list *nil_a, t_list *nil_b,
				t_cmd_list *nil_c, int pivot);
static int	pivot_or_more_exist(t_list *nil_b, int pivot);

void	move_to_nil_a_half_size(t_list *nil_a, t_list *nil_b
	, t_cmd_list *nil_c)
{
	int		pivot;
	int		before_size;
	int		before_sorted;

	if (move_to_nil_a_3_or_less_size(nil_a, nil_b, nil_c))
		return ;
	pivot = (max_rank_is(nil_b) - min_rank_is(nil_b) + 2 - 1) / 2;
	if (max_rank_is(nil_b) > (nil_a->max_size + 2 - 1) / 2)
		pivot += min_rank_is(nil_b);
	before_size = nil_b->now_size;
	before_sorted = nil_a->sorted;
	move_to_nil_a_pivot_or_more(nil_a, nil_b, nil_c, pivot);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
	move_to_nil_b_remaining(nil_a, nil_b, nil_c,
		(before_size - (nil_a->sorted - before_sorted) + 2 - 1) / 2);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
}

static int	move_to_nil_a_3_or_less_size(t_list *nil_a, t_list *nil_b
	, t_cmd_list *nil_c)
{
	if (nil_b->now_size == 0)
		return (1);
	if (nil_b->now_size == 1)
	{
		pa(nil_a, nil_b, nil_c);
		set_sorted(nil_a, nil_b, nil_c);
		return (1);
	}
	if (nil_b->now_size == 2)
	{
		solve_size_2_re(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		set_sorted(nil_a, nil_b, nil_c);
		return (1);
	}
	if (nil_b->now_size == 3)
	{
		solve_size_3_re(nil_a, nil_b, nil_c);
		pa_3_times(nil_a, nil_b, nil_c);
		set_sorted(nil_a, nil_b, nil_c);
		return (1);
	}
	return (0);
}

static void	pa_3_times(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	pa(nil_a, nil_b, nil_c);
	pa(nil_a, nil_b, nil_c);
	pa(nil_a, nil_b, nil_c);
}

static void	move_to_nil_a_pivot_or_more(t_list *nil_a, t_list *nil_b,
	t_cmd_list *nil_c, int pivot)
{
	while (pivot_or_more_exist(nil_b, pivot))
	{
		if (nil_b->next->rank >= pivot)
		{
			pa(nil_a, nil_b, nil_c);
			set_sorted(nil_a, nil_b, nil_c);
		}
		else
		{
			rb(nil_a, nil_b, nil_c);
			set_sorted(nil_a, nil_b, nil_c);
		}
	}
}

static int	pivot_or_more_exist(t_list *nil_b, int pivot)
{
	t_list	*p;

	if (nil_b->next == nil_b)
		return (0);
	p = nil_b->next;
	while (p != nil_b)
	{
		if (p->rank >= pivot)
			return (1);
		p = p->next;
	}
	return (0);
}

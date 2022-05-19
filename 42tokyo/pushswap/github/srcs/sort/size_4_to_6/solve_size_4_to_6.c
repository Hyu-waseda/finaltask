/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_4_to_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:31:18 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:59:28 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_ss_4_to_6(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
static int	is_321_or_231(t_list *nil_a);
static int	is_132_or_213(t_list *nil_b);
static void	solve_4_to_6_stak_b(
				t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

void	solve_size_4_to_6(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (!(4 <= nil_a->now_size) || !(nil_a->now_size <= 6))
		return ;
	while (nil_a->now_size > 3)
	{
		if (nil_a->next->rank <= nil_a->max_size - 3)
			pb(nil_a, nil_b, nil_c);
		else
		{
			if (r_is_near(nil_a, nil_a->max_size - 3))
				ra(nil_a, nil_b, nil_c);
			else
				rra(nil_a, nil_b, nil_c);
			check_sorted(nil_a, nil_b, nil_c);
		}
		optimize_ss_4_to_6(nil_a, nil_b, nil_c);
	}
	solve_size_3(nil_a, nil_b, nil_c);
	solve_4_to_6_stak_b(nil_a, nil_b, nil_c);
}

static void	optimize_ss_4_to_6(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_a->now_size < 2 || nil_b->now_size < 2)
		return ;
	if (nil_a->next->rank > nil_a->next->next->rank
		&& nil_b->next->rank < nil_b->next->next->rank)
	{
		if (is_321_or_231(nil_a) || is_132_or_213(nil_b))
			return ;
		ss(nil_a, nil_b, nil_c);
	}
}

static int	is_321_or_231(t_list *nil_a)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return (0);
	three = nil_a->next->rank;
	two = nil_a->next->next->rank;
	one = nil_a->next->next->next->rank;
	if (one < two && two < three)
		return (1);
	two = nil_a->next->rank;
	one = nil_a->next->next->rank;
	three = nil_a->next->next->next->rank;
	if (one < two && two < three)
		return (1);
	return (0);
}

static int	is_132_or_213(t_list *nil_b)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return (0);
	one = nil_b->next->rank;
	three = nil_b->next->next->rank;
	two = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return (1);
	two = nil_b->next->rank;
	one = nil_b->next->next->rank;
	three = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return (1);
	return (0);
}

static void	solve_4_to_6_stak_b(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	if (nil_b->now_size == 1)
		pa(nil_a, nil_b, nil_c);
	else if (nil_b->now_size == 2)
	{
		solve_size_2_re(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
	}
	else
	{
		solve_size_3_re(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
	}
}

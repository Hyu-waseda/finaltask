/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted_nil_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:40:15 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 16:45:40 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_1(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
static void	move_2(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

int	set_sorted_nil_b_top(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	i;

	i = 0;
	while (nil_b->now_size >= 1 && nil_b->next->rank == nil_a->sorted + 1)
	{
		pa(nil_a, nil_b, nil_c);
		ra(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	while (nil_b->now_size >= 2 && nil_b->next->next->rank == nil_a->sorted + 1)
	{
		sb(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		ra(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	return (i);
}

int	set_sorted_nil_b_bottom(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	i;

	i = 0;
	while (nil_b->now_size >= 2 && nil_b->prev->rank == nil_a->sorted + 1)
	{
		rrb(nil_a, nil_b, nil_c);
		pa(nil_a, nil_b, nil_c);
		ra(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	while (nil_b->now_size >= 3 && nil_b->prev->prev->rank == nil_a->sorted + 1)
	{
		move_1(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	while (nil_b->now_size >= 4
		&& nil_b->prev->prev->prev->rank == nil_a->sorted + 1)
	{
		move_2(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	return (i);
}

static void	move_1(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	rrb(nil_a, nil_b, nil_c);
	rrb(nil_a, nil_b, nil_c);
	pa(nil_a, nil_b, nil_c);
	ra(nil_a, nil_b, nil_c);
	rb(nil_a, nil_b, nil_c);
}

static void	move_2(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	rrb(nil_a, nil_b, nil_c);
	rrb(nil_a, nil_b, nil_c);
	rrb(nil_a, nil_b, nil_c);
	pa(nil_a, nil_b, nil_c);
	ra(nil_a, nil_b, nil_c);
	rb(nil_a, nil_b, nil_c);
	rb(nil_a, nil_b, nil_c);
}

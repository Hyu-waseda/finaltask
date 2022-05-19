/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted_nil_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:34:25 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 16:46:38 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

int	set_sorted_nil_a(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	i;

	i = 0;
	while (nil_a->next->rank == nil_a->sorted + 1)
	{
		ra(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	while (nil_a->now_size - nil_a->sorted >= 2
		&& nil_a->next->next->rank == nil_a->sorted + 1)
	{
		sa(nil_a, nil_b, nil_c);
		ra(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	while (nil_a->now_size - nil_a->sorted >= 3
		&& nil_a->next->next->next->rank == nil_a->sorted + 1)
	{
		move(nil_a, nil_b, nil_c);
		(nil_a->sorted)++;
		i++;
	}
	return (i);
}

static void	move(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	pb(nil_a, nil_b, nil_c);
	sa(nil_a, nil_b, nil_c);
	ra(nil_a, nil_b, nil_c);
	pa(nil_a, nil_b, nil_c);
}

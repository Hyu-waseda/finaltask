/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_3_re_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:46:29 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/08 11:49:29 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_123_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return ;
	one = nil_b->next->rank;
	two = nil_b->next->next->rank;
	three = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sb(nil_a, nil_b, nil_c);
	rrb(nil_a, nil_b, nil_c);
}

void	solve_132_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return ;
	one = nil_b->next->rank;
	three = nil_b->next->next->rank;
	two = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	rb(nil_a, nil_b, nil_c);
}

void	solve_213_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return ;
	two = nil_b->next->rank;
	one = nil_b->next->next->rank;
	three = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	rrb(nil_a, nil_b, nil_c);
}

void	solve_231_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return ;
	two = nil_b->next->rank;
	three = nil_b->next->next->rank;
	one = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sb(nil_a, nil_b, nil_c);
}

void	solve_312_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_b->now_size != 3)
		return ;
	three = nil_b->next->rank;
	one = nil_b->next->next->rank;
	two = nil_b->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sb(nil_a, nil_b, nil_c);
	rb(nil_a, nil_b, nil_c);
}

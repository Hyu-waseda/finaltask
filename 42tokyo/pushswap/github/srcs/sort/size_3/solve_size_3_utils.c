/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_3_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:42:37 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/08 11:42:44 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_321(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return ;
	three = nil_a->next->rank;
	two = nil_a->next->next->rank;
	one = nil_a->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sa(nil_a, nil_b, nil_c);
	rra(nil_a, nil_b, nil_c);
}

void	solve_312(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return ;
	three = nil_a->next->rank;
	one = nil_a->next->next->rank;
	two = nil_a->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	ra(nil_a, nil_b, nil_c);
}

void	solve_231(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return ;
	two = nil_a->next->rank;
	three = nil_a->next->next->rank;
	one = nil_a->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	rra(nil_a, nil_b, nil_c);
}

void	solve_213(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return ;
	two = nil_a->next->rank;
	one = nil_a->next->next->rank;
	three = nil_a->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sa(nil_a, nil_b, nil_c);
}

void	solve_132(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;
	int	three;

	if (nil_a->now_size != 3)
		return ;
	one = nil_a->next->rank;
	three = nil_a->next->next->rank;
	two = nil_a->next->next->next->rank;
	if (!(one < two && two < three))
		return ;
	sa(nil_a, nil_b, nil_c);
	ra(nil_a, nil_b, nil_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_2_re.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:49:12 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:59:25 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_size_2_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;

	if (nil_b->now_size != 2)
		return ;
	one = nil_b->next->rank;
	two = nil_b->next->next->rank;
	if (!(one < two))
		return ;
	sb(nil_a, nil_b, nil_c);
}

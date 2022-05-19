/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:10:07 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:10:30 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_size_2(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	one;
	int	two;

	if (nil_a->now_size != 2)
		return ;
	two = nil_a->next->rank;
	one = nil_a->next->next->rank;
	if (!(one < two))
		return ;
	sa(nil_a, nil_b, nil_c);
}

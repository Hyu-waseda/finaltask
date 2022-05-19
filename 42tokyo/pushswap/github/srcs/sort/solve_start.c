/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:39:53 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:40:17 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_start(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	solve_size_2(nil_a, nil_b, nil_c);
	solve_size_3(nil_a, nil_b, nil_c);
	solve_size_4_to_6(nil_a, nil_b, nil_c);
	check_sorted(nil_a, nil_b, nil_c);
	quick_sort(nil_a, nil_b, nil_c);
}

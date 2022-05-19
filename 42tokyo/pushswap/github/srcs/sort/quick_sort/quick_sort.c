/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:34:57 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 16:57:07 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_half(
				t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c, int pivot);
static void	second_half(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

void	quick_sort(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	int	pivot;

	check_sorted(nil_a, nil_b, nil_c);
	pivot = (nil_a->max_size + 2 - 1) / 2;
	nil_a->sorted = 0;
	move_to_nil_b_half(nil_a, nil_b, nil_c, pivot);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
	set_sorted(nil_a, nil_b, nil_c);
	while (nil_a->sorted < pivot)
		first_half(nil_a, nil_b, nil_c, pivot);
	move_to_nil_b_half2(nil_a, nil_b, nil_c, pivot);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
	set_sorted(nil_a, nil_b, nil_c);
	while (1)
		second_half(nil_a, nil_b, nil_c);
}

static void	first_half(
				t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c, int pivot)
{
	move_to_nil_b_remaining(nil_a, nil_b, nil_c, pivot - nil_a->sorted);
	set_sorted(nil_a, nil_b, nil_c);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
	set_sorted(nil_a, nil_b, nil_c);
}

static void	second_half(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	move_to_nil_b_remaining(
		nil_a, nil_b, nil_c, nil_a->max_size - nil_a->sorted);
	set_sorted(nil_a, nil_b, nil_c);
	move_to_nil_a_half_size(nil_a, nil_b, nil_c);
	set_sorted(nil_a, nil_b, nil_c);
}

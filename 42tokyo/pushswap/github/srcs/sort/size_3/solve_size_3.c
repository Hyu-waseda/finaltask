/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:40:58 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/08 11:41:21 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_size_3(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	solve_321(nil_a, nil_b, nil_c);
	solve_312(nil_a, nil_b, nil_c);
	solve_231(nil_a, nil_b, nil_c);
	solve_213(nil_a, nil_b, nil_c);
	solve_132(nil_a, nil_b, nil_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_size_3_re.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:45:09 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/08 11:45:40 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_size_3_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	solve_123_re(nil_a, nil_b, nil_c);
	solve_132_re(nil_a, nil_b, nil_c);
	solve_213_re(nil_a, nil_b, nil_c);
	solve_231_re(nil_a, nil_b, nil_c);
	solve_312_re(nil_a, nil_b, nil_c);
}

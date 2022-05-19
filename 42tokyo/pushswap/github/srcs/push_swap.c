/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:56:42 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:52:27 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*nil_a;
	t_list		*nil_b;
	t_cmd_list	*nil_c;

	check_argv(argc, argv);
	init_nil_ab(&nil_a, &nil_b, argc, argv);
	init_nil_c(nil_a, nil_b, &nil_c);
	check_sorted(nil_a, nil_b, nil_c);
	solve_start(nil_a, nil_b, nil_c);
	free_nils(nil_a, nil_b, nil_c);
}

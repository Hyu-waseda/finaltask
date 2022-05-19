/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nil_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:07:17 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/05/16 17:12:48 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_nil_a(t_list *nil_a, int argc);
static void	init_nil_b(t_list *nil_b, int argc);

void	init_nil_ab(t_list **nil_a, t_list **nil_b, int argc, char **argv)
{
	*nil_a = (t_list *)malloc(sizeof(t_list) * 1);
	*nil_b = (t_list *)malloc(sizeof(t_list) * 1);
	if (!(*nil_a) || !(*nil_b))
	{
		free_nils(*nil_a, *nil_b, NULL);
		error();
	}
	init_nil_a(*nil_a, argc);
	init_nil_b(*nil_b, argc);
	if (!make_first_nil_a(*nil_a, argc, argv))
	{
		free_nils(*nil_a, *nil_b, NULL);
		error();
	}
}

static void	init_nil_a(t_list *nil_a, int argc)
{
	nil_a->next = nil_a;
	nil_a->prev = nil_a;
	nil_a->max_size = argc - 1;
	nil_a->now_size = argc - 1;
	nil_a->value = 0;
	nil_a->rank = 0;
	nil_a->sorted = 0;
}

static void	init_nil_b(t_list *nil_b, int argc)
{
	nil_b->next = nil_b;
	nil_b->prev = nil_b;
	nil_b->max_size = argc - 1;
	nil_b->now_size = 0;
	nil_b->value = 0;
	nil_b->rank = 0;
}

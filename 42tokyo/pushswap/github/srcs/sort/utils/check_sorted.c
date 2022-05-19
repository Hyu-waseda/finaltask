/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:57:23 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:18:23 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_sorted(t_list *nil_a);

void	check_sorted(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	t_list	*p;
	int		i;

	count_sorted(nil_a);
	if (nil_a->now_size != nil_a->max_size)
		return ;
	p = nil_a->next;
	i = 1;
	while (p->next != nil_a)
	{
		if (p->rank != i)
			return ;
		i++;
		p = p->next;
	}
	optimize_cmd(nil_c);
	print_cmd(nil_c);
	free_nils(nil_a, nil_b, nil_c);
	exit(0);
	return ;
}

static void	count_sorted(t_list *nil_a)
{
	t_list	*p;
	int		i;

	p = nil_a->prev;
	i = 1;
	while (p->rank != 1)
	{
		if (p->rank - 1 != p->prev->rank)
			return ;
		i++;
		p = p->prev;
	}
	nil_a->sorted = i;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:49:57 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:04:19 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_rank_is(t_list *nil)
{
	int		max_rank;
	t_list	*p;

	max_rank = 0;
	p = nil->next;
	while (p != nil)
	{
		if (max_rank < p->rank)
			max_rank = p->rank;
		p = p->next;
	}
	return (max_rank);
}

int	min_rank_is(t_list *nil)
{
	int		min_rank;
	t_list	*p;

	min_rank = INT_MAX;
	p = nil->next;
	while (p != nil)
	{
		if (min_rank > p->rank)
			min_rank = p->rank;
		p = p->next;
	}
	return (min_rank);
}

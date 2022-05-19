/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_is_near.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:33:38 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/08 23:33:59 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_is_near(t_list *nil_a, int rank)
{
	t_list	*p;
	int		count_next;
	int		count_prev;

	p = nil_a->next;
	count_next = 0;
	while (p->rank > rank)
	{
		count_next++;
		p = p->next;
	}
	count_prev = 0;
	p = nil_a->prev;
	while (p->rank > rank)
	{
		count_prev++;
		p = p->prev;
	}
	if (count_prev >= count_next)
		return (1);
	else
		return (0);
}

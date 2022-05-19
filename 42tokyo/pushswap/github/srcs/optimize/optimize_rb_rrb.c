/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rb_rrb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:45:13 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:03:15 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_rb_rrb(t_cmd_list *p, t_cmd_list *tmp)
{
	t_cmd_list	*p1;
	int			count_rb;
	int			count_rrb;

	if (p->opt_next->cmd == RB || p->opt_next->cmd == RRB)
	{
		p1 = p->opt_next;
		tmp = p->opt_next;
		count_rb = 0;
		count_rrb = 0;
		while (p1->cmd == RB || p1->cmd == RRB)
		{
			if (p1->cmd == RB)
				count_rb++;
			if (p1->cmd == RRB)
				count_rrb++;
			if (count_rb == count_rrb)
				tmp = p1->opt_next;
			p1 = p1->opt_next;
		}
		p->opt_next = tmp;
	}
}

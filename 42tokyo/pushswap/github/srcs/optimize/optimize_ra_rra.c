/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ra_rra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:43:54 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:03:25 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_ra_rra(t_cmd_list *p, t_cmd_list *tmp)
{
	t_cmd_list	*p1;
	int			count_ra;
	int			count_rra;

	if (p->opt_next->cmd == RA || p->opt_next->cmd == RRA)
	{
		p1 = p->opt_next;
		tmp = p->opt_next;
		count_ra = 0;
		count_rra = 0;
		while (p1->cmd == RA || p1->cmd == RRA)
		{
			if (p1->cmd == RA)
				count_ra++;
			if (p1->cmd == RRA)
				count_rra++;
			if (count_ra == count_rra)
				tmp = p1->opt_next;
			p1 = p1->opt_next;
		}
		p->opt_next = tmp;
	}
}

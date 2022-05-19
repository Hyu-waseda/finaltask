/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rra_rrb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:16:06 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/06 18:15:59 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_rra_rrb(t_cmd_list *p)
{
	if ((p->opt_next->cmd == RRA && p->opt_next->opt_next->cmd == RRB)
		|| (p->opt_next->cmd == RRB && p->opt_next->opt_next->cmd == RRA))
	{
		p->opt_next->cmd = RRR;
		p->opt_next->opt_next = p->opt_next->opt_next->opt_next;
	}
}

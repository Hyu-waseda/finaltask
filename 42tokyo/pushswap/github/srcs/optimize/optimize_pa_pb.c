/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:51:07 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 22:59:52 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_pa_pb(t_cmd_list *p, t_cmd_list *tmp)
{
	t_cmd_list	*p1;
	int			count_pa;
	int			count_pb;

	if (p->opt_next->cmd == PA || p->opt_next->cmd == PB)
	{
		p1 = p->opt_next;
		tmp = p->opt_next;
		count_pa = 0;
		count_pb = 0;
		while (p1->cmd == PA || p1->cmd == PB)
		{
			if (p1->cmd == PA)
				count_pa++;
			if (p1->cmd == PB)
				count_pb++;
			if (count_pa == count_pb)
				tmp = p1->opt_next;
			p1 = p1->opt_next;
		}
		p->opt_next = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:07:05 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:00:05 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_sa(t_cmd_list *p, t_cmd_list *tmp)
{
	t_cmd_list	*p1;
	int			count_sa;

	if (p->opt_next->cmd == SA)
	{
		p1 = p->opt_next;
		tmp = p->opt_next;
		count_sa = 0;
		while (p1->cmd == SA)
		{
			if (p1->cmd == SA)
				count_sa++;
			if (count_sa % 2 == 0)
				tmp = p1->opt_next;
			p1 = p1->opt_next;
		}
		p->opt_next = tmp;
	}
}

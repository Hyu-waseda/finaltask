/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:43:06 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:00:20 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_sb(t_cmd_list *p, t_cmd_list *tmp)
{
	t_cmd_list	*p1;
	int			count_sb;

	if (p->opt_next->cmd == SB)
	{
		p1 = p->opt_next;
		tmp = p->opt_next;
		count_sb = 0;
		while (p1->cmd == SB)
		{
			if (p1->cmd == SB)
				count_sb++;
			if (count_sb % 2 == 0)
				tmp = p1->opt_next;
			p1 = p1->opt_next;
		}
		p->opt_next = tmp;
	}
}

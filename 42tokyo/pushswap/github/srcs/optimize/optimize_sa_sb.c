/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sa_sb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:58:52 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:02:38 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_sa_sb(t_cmd_list *p)
{
	if ((p->opt_next->cmd == SA && p->opt_next->opt_next->cmd == SB)
		|| (p->opt_next->cmd == SB && p->opt_next->opt_next->cmd == SA))
	{
		p->opt_next->cmd = SS;
		p->opt_next->opt_next = p->opt_next->opt_next->opt_next;
	}
}

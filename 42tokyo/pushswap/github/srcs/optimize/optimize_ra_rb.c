/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ra_rb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:13:36 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/06 18:15:53 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_ra_rb(t_cmd_list *p)
{
	if ((p->opt_next->cmd == RA && p->opt_next->opt_next->cmd == RB)
		|| (p->opt_next->cmd == RB && p->opt_next->opt_next->cmd == RA))
	{
		p->opt_next->cmd = RR;
		p->opt_next->opt_next = p->opt_next->opt_next->opt_next;
	}
}

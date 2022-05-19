/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:10:39 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 23:02:20 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_cmd(t_cmd_list *nil_c)
{
	t_cmd_list	*p;
	t_cmd_list	*tmp;
	int			i;

	i = 0;
	while (i < 10)
	{
		p = nil_c;
		tmp = p->opt_next;
		while (p->opt_next != nil_c)
		{
			optimize_ra_rb(p);
			optimize_sa_sb(p);
			optimize_rra_rrb(p);
			optimize_pa_pb(p, tmp);
			optimize_sa(p, tmp);
			optimize_sb(p, tmp);
			optimize_ra_rra(p, tmp);
			optimize_rb_rrb(p, tmp);
			p = p->opt_next;
		}
		i++;
	}
}

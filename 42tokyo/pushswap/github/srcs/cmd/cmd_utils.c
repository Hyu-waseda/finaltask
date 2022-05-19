/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:52:59 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/10 00:52:14 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_cmd(int cmd);

void	add_cmd(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c, int n)
{
	t_cmd_list	*new_node;

	new_node = (t_cmd_list *)malloc(sizeof(t_list) * 1);
	if (!new_node)
	{
		free_nils(nil_a, nil_b, nil_c);
		exit(1);
	}
	new_node->next = nil_c;
	new_node->prev = nil_c->prev;
	(nil_c->prev)->next = new_node;
	nil_c->prev = new_node;
	new_node->cmd = n;
	new_node->opt_next = nil_c;
	(nil_c->prev->prev)->opt_next = new_node;
}

void	print_cmd(t_cmd_list *nil_c)
{
	t_cmd_list	*p;

	p = nil_c->opt_next;
	while (p != nil_c)
	{
		write_cmd(p->cmd);
		p = p->opt_next;
	}
}

static void	write_cmd(int cmd)
{
	if (cmd == SA)
		write(1, "sa\n", 3);
	if (cmd == SB)
		write(1, "sb\n", 3);
	if (cmd == SS)
		write(1, "ss\n", 3);
	if (cmd == PA)
		write(1, "pa\n", 3);
	if (cmd == PB)
		write(1, "pb\n", 3);
	if (cmd == RA)
		write(1, "ra\n", 3);
	if (cmd == RB)
		write(1, "rb\n", 3);
	if (cmd == RR)
		write(1, "rr\n", 3);
	if (cmd == RRA)
		write(1, "rra\n", 4);
	if (cmd == RRB)
		write(1, "rrb\n", 4);
	if (cmd == RRR)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:50:51 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/14 01:51:39 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_list *nil);
static void	free_cmd_list(t_cmd_list *nil);

void	free_nils(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c)
{
	free_list(nil_a);
	free_list(nil_b);
	free_cmd_list(nil_c);
}

static void	free_list(t_list *nil)
{
	t_list	*p;
	t_list	*tmp;

	if (nil == NULL)
		return ;
	p = nil->next;
	while (p != nil)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(p);
	p = 0;
}

static void	free_cmd_list(t_cmd_list *nil)
{
	t_cmd_list	*p;
	t_cmd_list	*tmp;

	if (nil == NULL)
		return ;
	p = nil->next;
	while (p != nil)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(p);
	p = 0;
}

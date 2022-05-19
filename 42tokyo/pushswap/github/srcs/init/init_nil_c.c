/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nil_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:14:49 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 18:15:10 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nil_c(t_list *nil_a, t_list *nil_b, t_cmd_list **nil_c)
{
	*nil_c = (t_cmd_list *)malloc(sizeof(t_cmd_list) * 1);
	if (!(*nil_c))
	{
		free(nil_a);
		free(nil_b);
		return (error());
	}
	(*nil_c)->next = *nil_c;
	(*nil_c)->prev = *nil_c;
	(*nil_c)->cmd = 0;
	(*nil_c)->opt_next = *nil_c;
}

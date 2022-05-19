/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_first_nil_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:02:27 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/05/16 17:11:47 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoi(const char *str);
static int			same_value_exist(t_list *nil_a, int n);
static int			add_new_node_to_nil_a(t_list *nil_a, long long n);
static void			rank_nil_a(t_list *nil_a);

int	make_first_nil_a(t_list *nil_a, int argc, char **argv)
{
	int			i;
	long long	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < INT_MIN || INT_MAX < n
			|| same_value_exist(nil_a, n) || !add_new_node_to_nil_a(nil_a, n))
			return (0);
		i++;
	}
	rank_nil_a(nil_a);
	return (1);
}

static long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && n * (-1) < INT_MIN))
			return (n * sign);
		i++;
	}
	return (n * sign);
}

static int	same_value_exist(t_list *nil_a, int n)
{
	t_list	*p;

	p = nil_a->next;
	while (p != nil_a)
	{
		if (n == p->value)
		{
			return (1);
		}
		p = p->next;
	}
	return (0);
}

static int	add_new_node_to_nil_a(t_list *nil_a, long long n)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_node)
		return (0);
	new_node->next = nil_a;
	new_node->prev = nil_a->prev;
	(nil_a->prev)->next = new_node;
	nil_a->prev = new_node;
	new_node->value = n;
	return (1);
}

static void	rank_nil_a(t_list *nil_a)
{
	t_list	*p1;
	t_list	*p2;
	int		rank;

	p1 = nil_a->next;
	while (p1 != nil_a)
	{
		rank = 1;
		p2 = p1->next;
		while (p2 != p1)
		{
			if (p2 != nil_a && p1->value > p2->value)
				rank++;
			p2 = p2->next;
		}
		p1->rank = rank;
		p1 = p1->next;
	}
}

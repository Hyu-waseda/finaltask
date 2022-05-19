/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:08:53 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/07 18:13:30 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_number(char *s);
static int	ft_isdigit(int c);

void	check_argv(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		is_number(argv[i]);
		i++;
	}
}

static void	is_number(char *s)
{
	int	count_minus;
	int	i;

	count_minus = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
		{
			if (s[i] != '-' || (s[i] == '-' && !ft_isdigit(s[i + 1])))
				error();
			else
				count_minus++;
		}
		if (count_minus == 2)
			error();
		i++;
	}
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

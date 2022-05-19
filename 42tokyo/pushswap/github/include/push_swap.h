/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:22:56 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/05/16 17:11:59 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				max_size;
	int				now_size;
	int				value;
	int				rank;
	int				sorted;
}		t_list;

typedef struct s_cmd_list
{
	struct s_cmd_list	*next;
	struct s_cmd_list	*prev;
	int					cmd;
	struct s_cmd_list	*opt_next;
}		t_cmd_list;

void	check_argv(int argc, char **argv);
void	init_nil_ab(t_list **nil_a, t_list **nil_b, int argc, char **argv);
void	init_nil_c(t_list *nil_a, t_list *nil_b, t_cmd_list **nil_c);
int		make_first_nil_a(t_list *nil_a, int argc, char **argv);
void	free_nils(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

void	error(void);

void	sa(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	sb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	ss(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	pa(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	pb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	ra(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	rb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	rr(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	rra(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	rrb(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	rrr(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	add_cmd(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c, int n);
void	print_cmd(t_cmd_list *nil_c);

void	optimize_cmd(t_cmd_list *nil_c);
void	optimize_sa(t_cmd_list *p, t_cmd_list *tmp);
void	optimize_sb(t_cmd_list *p, t_cmd_list *tmp);
void	optimize_pa_pb(t_cmd_list *p, t_cmd_list *tmp);
void	optimize_ra_rra(t_cmd_list *p, t_cmd_list *tmp);
void	optimize_rb_rrb(t_cmd_list *p, t_cmd_list *tmp);
void	optimize_ra_rb(t_cmd_list *p);
void	optimize_rra_rrb(t_cmd_list *p);
void	optimize_sa_sb(t_cmd_list *p);

void	solve_size_2(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_size_2_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_size_3(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_321(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_312(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_231(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_213(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_132(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_size_3_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_123_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_132_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_213_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_231_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_312_re(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	solve_size_4_to_6(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);

int		set_sorted(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
int		set_sorted_nil_a(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
int		set_sorted_nil_b_top(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
int		set_sorted_nil_b_bottom(
			t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	check_sorted(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
int		r_is_near(t_list *nil_a, int rank);

void	solve_start(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	quick_sort(t_list *nil_a, t_list *nil_b, t_cmd_list *nil_c);
void	move_to_nil_b_half(t_list *nil_a, t_list *nil_b,
			t_cmd_list *nil_c, int pivot);
void	move_to_nil_b_half2(t_list *nil_a, t_list *nil_b,
			t_cmd_list *nil_c, int pivot);
void	move_to_nil_b_remaining(t_list *nil_a, t_list *nil_b,
			t_cmd_list *nil_c, int n);
void	move_to_nil_a_half_size(t_list *nil_a, t_list *nil_b,
			t_cmd_list *nil_c);

int		max_rank_is(t_list *nil);
int		min_rank_is(t_list *nil);

#endif
NAME	= push_swap
SRCS	= push_swap.c \
			check_argv.c \
			init_nil_ab.c \
			init_nil_c.c \
			make_first_nil_a.c \
			free_nils.c \
			error.c \
			sa.c \
			sb.c \
			ss.c \
			pa.c \
			pb.c \
			ra.c \
			rb.c \
			rr.c \
			rra.c \
			rrb.c \
			rrr.c \
			cmd_utils.c \
			optimize_cmd.c \
			optimize_sa.c \
			optimize_sb.c \
			optimize_pa_pb.c \
			optimize_ra_rra.c \
			optimize_rb_rrb.c \
			optimize_sa_sb.c \
			optimize_ra_rb.c \
			optimize_rra_rrb.c \
			solve_start.c \
			solve_size_2.c \
			solve_size_2_re.c \
			solve_size_3.c \
			solve_size_3_utils.c \
			solve_size_3_re.c \
			solve_size_3_re_utils.c \
			solve_size_4_to_6.c \
			set_sorted.c \
			set_sorted_nil_a.c \
			set_sorted_nil_b.c \
			check_sorted.c \
			r_is_near.c \
			quick_sort.c \
			move_to_nil_a.c \
			move_to_nil_b.c \
			quick_sort_utils.c

HEADER	= include
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
SRC_DIR	:=	./srcs
OBJ_DIR	:=	./objs
VPATH	:=	srcs:\
			srcs/cmd:\
			srcs/optimize:\
			srcs/init:\
			srcs/free:\
			srcs/sort:\
			srcs/sort/size_2:\
			srcs/sort/size_3:\
			srcs/sort/size_4_to_6:\
			srcs/sort/quick_sort:\
			srcs/sort/utils:\
			srcs/validate

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	mkdir -p $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re
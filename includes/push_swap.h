/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 20:01:58 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:50:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define IS_NBR		-10

# define STACK_A	20
# define STACK_B	30
# define STACK_AB	40

# define BEFORE_MID	1
# define AFTER_MID	2

# define SWAP_A		1
# define SWAP_B		2
# define PUSH_A		3
# define PUSH_B		4
# define ROT_A		5
# define ROT_B		6
# define RROT_A		7
# define RROT_B		8
# define R_AB		9
# define RR_AB		10
# define SWAP_AB	11

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define STOP		"\x1b[0m"

typedef struct		s_link
{
	long			n;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_flags
{
	int				colors;
	int				step_by_step;
	int				print_stacks;
	int				mooves;
	int				read_from_file;
	char			*filename;
}					t_flags;

typedef struct		s_stack
{
	long			len;
	t_link			*head;
}					t_stack;

typedef struct		s_mooves
{
	long			nb;
	t_link			*head;
	t_link			*queque;
}					t_mooves;

typedef struct		s_data
{
	t_flags			*flags;
	t_stack			*a;
	t_stack			*b;
	t_mooves		*mvs;
}					t_data;

/*
**	PUSH_SWAP
*/
int					push_swap(t_data *data);

/*
**	SORTS
*/
int					sort_smart(t_data *data);
int					sort_select(t_data *data);
int					sort_three(t_data *data);
int					sort_split_select(t_data *data);
int					sort_sselect(t_data *data);

/*
**	STACK
*/
t_stack				*stack_from_args(int argc, char **argv);
t_stack				*stack_from_file(char *filename);

/*
**	PARSE
*/
t_flags				*ps_parse_flags(int argc, char **argv);
t_stack				*ps_parse_stack(t_data *data, int argc, char **argv);

/*
**	CHECK
*/
int					check_filename(char *filename);

/*
**	CHECK_LIST_ARGS
*/
int					check_arg(char *arg);
int					check_list_args(int argc, char **argv, int skip);

/*
**	STATUS
*/
int					stack_lenght(t_stack *stack);
int					is_empty(t_stack *stack);
int					is_swapped(t_stack *stack);
int					is_rev_sorted(t_stack *stack);
int					is_sorted(t_stack *stack);

/*
**	MOOVES
*/
void				push(t_data *data, int w_stack);
void				swap(t_stack *stack, t_mooves **mooves, int w_stack);
void				rotate(t_stack **stack, t_mooves **mooves, int w_stack);
void				rrotate(t_stack **stack, t_mooves **mooves, int w_stack);
void				swap_ab(t_stack *stack_a, t_stack *stack_b,
		t_mooves **mooves);
void				rotate_ab(t_stack *stack_a, t_stack *stack_b,
		t_mooves **mooves);
void				rrotate_ab(t_stack *stack_a, t_stack *stack_b,
		t_mooves **mooves);

/*
**	MOOVE_AND_PRINT
*/
void				push_and_print(t_data *data, int w_stack);
void				swap_and_print(t_data *data, int w_stack);
void				rotate_and_print(t_data *data, int w_stack);
void				rrotate_and_print(t_data *data, int w_stack);
/*
**	LIST_MINMAX
*/
int					list_min(t_stack *stack);
int					list_max(t_stack *stack);

/*
**	HELP
*/
void				free_splitt(char **splitt);
t_link				*last_link(t_stack *stack);
int					set_min(t_stack *stack, int *pos);
void				add_moove(t_mooves **mooves, int mv);
int					pop(t_stack **stack);

/*
**	NEW
*/
t_link				*new_link(long const n, t_link *prev);
t_flags				*new_flags(void);
t_stack				*new_stack(void);
t_mooves			*new_mooves(long n);
t_data				*new_data(void);

/*
**	PRINT
*/
void				print_mooves(t_mooves *mooves, int colors);
void				print_w_stack(t_stack *stack, char c, int colors);
void				print_stack(t_stack *stack, int colors, char c);
int					print_stacks(t_data *data);
int					print_result(t_data *data);
void				which_moove(int mv, int colors);
int					ft_printf(const char *format, ...);

/*
**	FREE
*/
void				free_linked(t_link *l);
void				free_flags(t_flags *f);
void				free_stack(t_stack *stack);
void				free_mooves(t_mooves *mvs);
void				free_data(t_data *data);
void				free_splitt(char **split);

/*
**	ERRORS 00-01
*/
int					usage_error(void);
int					flag_error(void);
int					filename_error(void);
int					close_error(void);
int					malloc_error(void);
int					list_error(void);

#endif

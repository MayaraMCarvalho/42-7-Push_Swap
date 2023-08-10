/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:21:17 by macarval          #+#    #+#             */
/*   Updated: 2023/05/12 13:09:48 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libs/ft_printf/ft_printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define PA 5
# define PB 6
# define RRA 7
# define RRB 8

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// Getters
t_stack	*get_first(int num);
int		get_last(t_stack *stack);
void	get_min(t_stack *list, int *min);
void	get_max(t_stack *list, int *max);
int		get_med(t_stack *list, int pos);

// Inserts
t_stack	*insert_front(t_stack *list, int num);
void	insert_second(t_stack **lst, t_stack *node);
void	insert_last(t_stack **lst, t_stack *new);

// Instructions
int		is_ss(t_stack *instr);
int		is_rr(t_stack *instr);
int		is_rrr(t_stack *instr);
int		make_instr(t_stack **instr, int move);

// Libft Custom
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isdigit_modify(char *argv);
int		ft_atoi_modify(const char *str);

// Movements
int		swap(t_stack **stack);
int		rotate(t_stack **stack);
int		reverse(t_stack **stack);
int		push(t_stack **stack_1, t_stack **stack_2);

// Print
void	print_comm(int num);
void	print_stack(t_stack *list);
void	print_instr(t_stack *instr);

// Remove
t_stack	*remove_first(t_stack *lst);
void	remove_last(t_stack *stack);
t_stack	*remove_min(t_stack	*list, int min);

// Sorting
void	sorting(t_stack **a, int argc);
void	order10(t_stack **a, t_stack **b, t_stack **instr);
void	order100(t_stack **a, t_stack **b, t_stack **instr);

// Pre Sorting
t_stack	*med_list(t_stack *a, int num);
void	get_med_list(t_stack **a, t_stack **med, int argc);
void	pre_order_final(t_stack **a, t_stack **b, t_stack **instr);
void	pre_order(t_stack **a, t_stack **b, t_stack **instr, t_stack *med);

// Stack
void	free_stack(t_stack *list);
int		size_stack(t_stack *list);
t_stack	*order_stack(t_stack	*list);
t_stack	*duplicate_stack(t_stack *list);
t_stack	*make_stack(int argc, char *argv[]);

// Utils
int		more_two(t_stack *list);
int		over_med(t_stack *list, int med);
int		under_med(t_stack *list, int med, int min);

// Verify Arguments
int		is_int(char *argv[]);
int		is_duplicate(int argc, char *argv[]);
int		is_disordered(t_stack *a, t_stack *b);
void	verify_limits(int r, const char *str, int s, int i);

// Teste Results DELETAR
void	print_file_comm(int num, int fd);
void	inst_reduce(t_stack *instr);
void	instr_complete(t_stack *instr);

#endif

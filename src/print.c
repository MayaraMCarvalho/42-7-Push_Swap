/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:05:47 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:27 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_instr(t_stack *instr)
{
	int	control;

	while (instr != NULL)
	{
		control = 0;
		if (instr->next && is_ss(instr))
			ft_printf("ss\n");
		else if (instr->next && is_rr(instr))
			ft_printf("rr\n");
		else if (instr->next && is_rrr(instr))
			ft_printf("rrr\n");
		else
		{
			print_comm(instr->content);
			instr = instr->next;
			control = 1;
		}
		if (control == 0)
			instr = instr->next->next;
	}
}

void	print_comm(int num)
{
	if (num == SA)
		ft_printf("sa\n");
	else if (num == SB)
		ft_printf("sb\n");
	else if (num == PA)
		ft_printf("pa\n");
	else if (num == PB)
		ft_printf("pb\n");
	else if (num == RA)
		ft_printf("ra\n");
	else if (num == RB)
		ft_printf("rb\n");
	else if (num == RRA)
		ft_printf("rra\n");
	else if (num == RRB)
		ft_printf("rrb\n");
}

void	print_stack(t_stack *list)
{
	ft_printf("\n");
	while (list != NULL)
	{
		ft_printf("%i\n", list->content);
		list = list->next;
	}
}

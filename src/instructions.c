/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:43:39 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:48:45 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ss(t_stack *instr)
{
	if ((instr->content == SA && instr->next->content == SB)
		|| (instr->content == SB && instr->next->content == SA))
		return (1);
	return (0);
}

int	is_rr(t_stack *instr)
{
	if ((instr->content == RA && instr->next->content == RB)
		|| (instr->content == RB && instr->next->content == RA))
		return (1);
	return (0);
}

int	is_rrr(t_stack *instr)
{
	if ((instr->content == RRA && instr->next->content == RRB)
		|| (instr->content == RRB && instr->next->content == RRA))
		return (1);
	return (0);
}

int	make_instr(t_stack **instr, int move)
{
	t_stack	*node;

	node = NULL;
	insert_last(instr, insert_front(node, move));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:58:03 by macarval          #+#    #+#             */
/*   Updated: 2023/02/14 02:10:09 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting(t_stack **a, int argc)
{
	t_stack	*b;
	t_stack	*med;
	t_stack	*instr;

	b = NULL;
	instr = NULL;
	if (argc - 1 > 10)
	{
		get_med_list(a, &med, argc);
		pre_order(a, &b, &instr, med);
		free_stack(med);
		if ((*a)->content < (*a)->next->content && rotate(a))
			make_instr(&instr, RA);
	}
	while (is_disordered(*a, b))
	{
		if (argc - 1 <= 10)
			order10(a, &b, &instr);
		else
			order100(a, &b, &instr);
	}
	print_instr(instr);
	free_stack(b);
	free_stack(instr);
}

void	order10(t_stack **a, t_stack**b, t_stack **instr)
{
	if (!is_disordered(*a, NULL) && *b && push(a, b))
		make_instr(instr, PA);
	else if ((*a)->content > get_last(*a))
	{
		if ((*a)->content < (*a)->next->content && reverse(a))
			make_instr(instr, RRA);
		else if (rotate(a))
			make_instr(instr, RA);
	}
	else if ((*a)->content > (*a)->next->content && swap(a))
		make_instr(instr, SA);
	else if (*a && push(b, a))
		make_instr(instr, PB);
	if (*b && (*b)->next
		&& (*b)->content < (*b)->next->content && swap(b))
		make_instr(instr, SB);
}

void	order100(t_stack **a, t_stack **b, t_stack **instr)
{	
	int	control;

	control = 0;
	if ((*b) && (*b)->next && (*b)->content < (*b)->next->content && rotate(b))
		control = make_instr(instr, RB);
	else if ((*b) && (*b)->content < get_last(*b) && reverse(b))
		control = make_instr(instr, RRB);
	if ((*b) && (*a)->content < (*b)->content && rotate(a))
		control = make_instr(instr, RA);
	else if ((*b) && (*b)->content < get_last(*a) && reverse(a))
		control = make_instr(instr, RRA);
	if (control == 0 && push(a, b))
		make_instr(instr, PA);
	if (!(*b) && get_last(*a) < (*a)->content
		&& (*a)->content < (*a)->next->content && reverse(a))
		make_instr(instr, RRA);
}

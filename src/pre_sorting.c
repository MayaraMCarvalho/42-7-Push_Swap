/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:01:04 by macarval          #+#    #+#             */
/*   Updated: 2023/02/14 02:09:47 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_med_list(t_stack **a, t_stack **med, int argc)
{
	if (argc - 1 < 500)
		*med = med_list(*a, 5);
	else
		*med = med_list(*a, 11);
}

void	pre_order(t_stack **a, t_stack **b, t_stack **instr, t_stack *med)
{
	int	max;
	int	min;
	int	control;

	get_min(*a, &min);
	get_max(*a, &max);
	while (med != NULL)
	{
		while (*a && under_med(*a, med->content, min))
		{
			control = 0;
			if (((*a)->content == min || (*a)->content == max
					|| (*a)->content >= med->content) && rotate(a))
				control = make_instr(instr, RA);
			if (*b && (*b)->content < get_last(*b) && rotate(b))
				make_instr(instr, RB);
			if (control == 0 && push(b, a))
				make_instr(instr, PB);
		}
		med = med->next;
	}
	pre_order_final(a, b, instr);
}

void	pre_order_final(t_stack **a, t_stack **b, t_stack **instr)
{
	int	max;
	int	min;

	get_min(*a, &min);
	get_max(*a, &max);
	while (more_two(*a) > 2)
	{
		if (((*a)->content == min || (*a)->content == max) && rotate(a))
			make_instr(instr, RA);
		else if (push(b, a))
			make_instr(instr, PB);
	}
}

t_stack	*med_list(t_stack *a, int num)
{
	t_stack	*med;
	t_stack	*node;
	int		tam;
	int		i;

	i = 0;
	med = NULL;
	tam = size_stack(a);
	while (++i < num)
	{
		node = NULL;
		node = insert_front(node, get_med(a, tam * i / num));
		insert_last(&med, node);
	}
	return (med);
}

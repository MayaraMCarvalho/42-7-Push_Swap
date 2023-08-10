/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:37:10 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:37 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (*stack)
	{
		temp = *stack;
		node = get_first(temp->content);
		*stack = remove_first(*stack);
		insert_second(stack, node);
		return (1);
	}
	return (0);
}

int	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	if (*stack_2)
	{
		temp = *stack_2;
		*stack_1 = insert_front(*stack_1,
				temp->content);
		*stack_2 = remove_first(*stack_2);
		return (1);
	}
	return (0);
}

int	rotate(t_stack **stack)
{	
	t_stack	*node;
	t_stack	*temp;

	temp = *stack;
	if (*stack && temp->next)
	{
		node = get_first(temp->content);
		*stack = remove_first(*stack);
		insert_last(stack, node);
		return (1);
	}
	return (0);
}

int	reverse(t_stack **stack)
{	
	int		num;
	t_stack	*temp;

	temp = *stack;
	if (*stack && temp->next)
	{
		num = get_last(*stack);
		remove_last(*stack);
		*stack = insert_front(*stack, num);
		return (1);
	}
	return (0);
}

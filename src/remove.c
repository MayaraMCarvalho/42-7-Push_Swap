/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:04:01 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:13 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*remove_first(t_stack *lst)
{
	t_stack	*temp;

	if (!lst->next)
	{
		free(lst);
		return (NULL);
	}
	if (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		lst->prev = NULL;
		free(temp);
	}	
	return (lst);
}

void	remove_last(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	stack->prev->next = NULL;
	stack->prev = NULL;
	free(stack);
}

t_stack	*remove_min(t_stack	*list, int min)
{
	t_stack	*temp;
	t_stack	*prev;

	temp = list;
	prev = NULL;
	while (temp != NULL && temp->content != min)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL)
		list = temp->next;
	else
		prev->next = temp->next;
	free(temp);
	return (list);
}

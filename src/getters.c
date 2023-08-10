/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:54:27 by macarval          #+#    #+#             */
/*   Updated: 2023/05/31 13:39:02 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_first(int num)
{
	t_stack	*node;

	node = NULL;
	node = insert_front(node, num);
	return (node);
}

int	get_last(t_stack *stack)
{
	int	num;

	while (stack->next != NULL)
		stack = stack->next;
	num = stack->content;
	return (num);
}

void	get_min(t_stack *list, int *min)
{
	*min = list->content;
	while (list != NULL)
	{
		if (*min > list->content)
			*min = list->content;
		list = list->next;
	}
}

void	get_max(t_stack *list, int *max)
{
	*max = list->content;
	while (list != NULL)
	{
		if (*max < list->content)
			*max = list->content;
		list = list->next;
	}
}

int	get_med(t_stack *list, int pos)
{
	int		med;
	int		i;
	t_stack	*node;
	t_stack	*lst;

	i = 0;
	lst = order_stack(list);
	node = lst;
	while (i++ < pos)
		node = node->next;
	med = node->content;
	free_stack(lst);
	return (med);
}

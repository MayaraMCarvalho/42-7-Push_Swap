/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:48:24 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:55 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*insert_front(t_stack *new, int num)
{
	t_stack	*node;

	node = (t_stack *) malloc (sizeof (t_stack));
	if (!node)
		return (0);
	node->content = num;
	node->prev = NULL;
	node->next = new;
	if (new != NULL)
		new->prev = node;
	return (node);
}	

void	insert_second(t_stack **lst, t_stack *node)
{
	t_stack	*list;

	if (!lst)
		return ;
	if (*lst)
	{
		list = *lst;
		node->prev = list;
		if (list->next != NULL)
		{
			list->next->prev = node;
			node->next = list->next;
		}
		list->next = node;
	}
	else
		*lst = node;
}	

void	insert_last(t_stack **lst, t_stack *new)
{
	t_stack	*list;

	if (!lst)
		return ;
	if (*lst)
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->prev = list;
	}
	else
		*lst = new;
}

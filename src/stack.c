/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:41:15 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:02 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *list)
{
	t_stack	*temp;
	t_stack	*next;

	temp = list;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

t_stack	*make_stack(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*node;
	int		i;
	int		num;

	i = 0;
	stack = NULL;
	while (i++ < argc - 1)
	{
		node = NULL;
		num = ft_atoi(argv[i]);
		node = insert_front(node, num);
		insert_last(&stack, node);
	}
	return (stack);
}

int	size_stack(t_stack *list)
{
	int	i;

	i = 0;
	while (list != NULL && ++i)
		list = list->next;
	return (i);
}

t_stack	*duplicate_stack(t_stack *list)
{
	t_stack	*lst;
	t_stack	*node;

	lst = NULL;
	while (list != NULL)
	{
		node = NULL;
		node = insert_front(node, list->content);
		insert_last(&lst, node);
		list = list->next;
	}
	return (lst);
}

t_stack	*order_stack(t_stack	*list)
{
	t_stack	*lst;
	t_stack	*node;
	t_stack	*temp;
	int		min;

	lst = duplicate_stack(list);
	temp = NULL;
	while (lst != NULL)
	{
		get_min(lst, &min);
		lst = remove_min(lst, min);
		node = NULL;
		node = insert_front(node, min);
		insert_last(&temp, node);
	}
	return (temp);
}

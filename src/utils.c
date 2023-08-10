/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:17:50 by macarval          #+#    #+#             */
/*   Updated: 2023/02/10 19:19:31 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	under_med(t_stack *list, int med, int min)
{
	while (list != NULL)
	{
		if (list->content < med && list->content != min)
			return (1);
		list = list->next;
	}
	return (0);
}

int	over_med(t_stack *list, int med)
{
	while (list != NULL)
	{
		if (list->content >= med)
			return (1);
		list = list->next;
	}
	return (0);
}

int	more_two(t_stack *list)
{
	int	i;

	i = 0;
	while (list != NULL && ++i < 3)
		list = list->next;
	return (i);
}

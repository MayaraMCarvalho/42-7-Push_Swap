/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:40:59 by macarval          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:13 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(char *argv[])
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_isdigit_modify(argv[i]))
			return (0);
		ft_atoi_modify(argv[i]);
	}
	return (1);
}

int	is_duplicate(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argc > 2 && i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	verify_limits(int r, const char *str, int s, int i)
{
	if (r >= INT_MAX / 10 && str[i])
	{
		if ((str[s] != '-' && str[i] > '7')
			|| (str[s] == '-' && str[i] > '8')
			|| r > INT_MAX / 10)
		{
			ft_printf("Error\n");
			exit(1);
		}	
	}
}

int	is_disordered(t_stack *a, t_stack *b)
{
	if (b)
		return (1);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

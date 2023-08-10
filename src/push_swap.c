/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:35:16 by macarval          #+#    #+#             */
/*   Updated: 2023/02/09 19:49:21 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{	
	t_stack	*a;

	if (argc > 2)
	{
		if (is_duplicate(argc, argv) || !is_int(argv))
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
		{
			a = make_stack(argc, argv);
			if (a == NULL)
				return (0);
			if (!is_disordered(a, NULL))
			{
				free_stack(a);
				exit(0);
			}
			sorting(&a, argc);
			free_stack(a);
		}
	}
	return (0);
}

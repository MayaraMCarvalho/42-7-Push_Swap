/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_custom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:48:51 by macarval          #+#    #+#             */
/*   Updated: 2023/02/07 22:26:44 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_modify(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		s = i;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - 48;
		i++;
		verify_limits(r, str, s, i);
	}
	if (str[s] == '-')
		r = -r;
	return (r);
}

int	ft_isdigit_modify(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		s = i;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		r = (r * 10) + str[i] - 48;
		i++;
	}
	if (str[s] == 45)
		r = -r;
	return (r);
}

int	ft_isdigit(int c)
{
	int	r;

	r = (c >= '0' && c <= '9');
	return (r);
}

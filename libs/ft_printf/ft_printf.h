/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:24:22 by macarval          #+#    #+#             */
/*   Updated: 2022/06/07 03:29:15 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb, int *cont);
void	ft_putchar(char c, int *cont);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *cont);
void	ft_putptr(long int ptr, int *cont);
void	ft_putun(int nb, char c, int *cont);
void	ft_puthex(long int nb, char c, int *cont);
void	ft_pdi_bonus(va_list res, char j, int *cont);
void	ft_puthexun(unsigned long int nb, char c, int *cont);
int		ft_format(va_list res, const char *str, int i, int *cont);
int		ft_p_spaceplus(va_list res, const char *str, int i, int *cont);
int		ft_format_bonus(va_list res, const char *str, int i, int *cont);

#endif
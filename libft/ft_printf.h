/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:13:15 by frcastil          #+#    #+#             */
/*   Updated: 2023/06/19 12:21:12 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printchar(char c);
int		ft_printdec(int nb);
int		ft_printhexa(unsigned long long nb, char ch);
int		ft_printptr(unsigned long long ptr);
int		ft_printstr(char *str);
int		ft_printunsigned(unsigned int nb);
int		ft_putnbr(int n);
int		ft_printf(char const *type, ...);

#endif
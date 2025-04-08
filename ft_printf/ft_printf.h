/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:41:49 by pde-cast          #+#    #+#             */
/*   Updated: 2024/12/02 16:30:55 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	printchar(char chr);
int	printstr(char *str);
int	printint(int i);
int	printperc(void);
int	printhexc(unsigned long c);
int	printhexl(unsigned long c);
int	printptr(void *p);
int	formattype(const char c);
int	formatchoice(const char c, va_list args);
int	ft_printf(const char *format, ...);
int	printunsint(unsigned int i);

#endif

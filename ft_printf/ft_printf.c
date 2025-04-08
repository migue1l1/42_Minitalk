/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:46:55 by pde-cast          #+#    #+#             */
/*   Updated: 2024/12/02 16:24:43 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <limits.h>
//#define LONG_MIN  (-__LONG_MAX__ -1L)

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		c;
	va_list	args;

	ret = 0;
	c = 0;
	va_start(args, format);
	while (format[c] != '\0')
	{
		if (format[c] == '%')
		{
			if (formattype(format[c + 1]) == 1)
			{
				ret += formatchoice(format[c++ + 1], args);
			}
		}
		else
		{
			write(1, &format[c], 1);
			ret++;
		}
		c++;
	}
	va_end (args);
	return (ret);
}

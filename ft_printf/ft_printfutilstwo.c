/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutilstwo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:55:53 by pde-cast          #+#    #+#             */
/*   Updated: 2024/12/02 16:23:04 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhexc(unsigned long c)
{
	char	hexnr[100];
	int		ret;
	int		i2;
	int		temp;

	i2 = 0;
	ret = 0;
	if (c == 0)
		ret += write(1, "0", 1);
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp += 48;
		else if (temp >= 10)
			temp += 55;
		hexnr[i2++] = temp;
		c = c / 16;
	}
	while (i2 > 0)
		ret += write(1, &hexnr[--i2], 1);
	return (ret);
}

int	printhexl(unsigned long c)
{
	char			hexnr[100];
	int				ret;
	int				i2;
	int				temp;

	i2 = 0;
	ret = 0;
	if (c == 0)
		ret += write(1, "0", 1);
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hexnr[i2++] = temp;
		c /= 16;
	}
	while (i2 > 0)
		ret += write(1, &hexnr[--i2], 1);
	return (ret);
}

int	printptr(void *p)
{
	int	ret;

	if (!p)
		return (write(1, &"(nil)", 5));
	ret = printstr("0x");
	ret += printhexl((unsigned long)p);
	return (ret);
}

int	formattype(const char c)
{
	if (c == 'c' || c == '%')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'i' || c == 'd')
		return (1);
	if (c == 'u')
		return (1);
	if (c == '%')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	formatchoice(const char c, va_list args)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = printchar(va_arg(args, int));
	if (c == 's')
		ret = printstr(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		ret = printint(va_arg(args, int));
	if (c == 'u')
		ret = printunsint(va_arg(args, unsigned int));
	if (c == '%')
		ret = printchar('%');
	if (c == 'x')
		ret = printhexl(va_arg(args, unsigned int));
	if (c == 'X')
		ret = printhexc(va_arg(args, unsigned int));
	if (c == 'p')
		ret = printptr(va_arg(args, void *));
	return (ret);
}

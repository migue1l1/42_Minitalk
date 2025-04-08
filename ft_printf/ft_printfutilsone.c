/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutilsone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:53:50 by pde-cast          #+#    #+#             */
/*   Updated: 2024/12/02 16:23:57 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char chr) //%c
{
	write(1, &chr, 1);
	return (1);
}

int	printstr(char *str) //%s
{
	int	c;

	c = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[c] != '\0')
		c += write(1, &str[c], 1);
	return (c);
}

int	printint(int i)
{
	long	n2;
	int		ret;

	ret = 0;
	n2 = i;
	if (n2 < 0)
	{
		printchar('-');
		n2 *= -1;
		ret++;
	}
	if (n2 >= 0 && n2 <= 9)
		ret += printchar(n2 + '0');
	else
	{
		ret += printint(n2 / 10);
		ret += printint(n2 % 10);
	}
	return (ret);
}

int	printunsint(unsigned int i)
{
	unsigned long	n2;
	int				ret;

	ret = 0;
	n2 = i;
	if ((int)n2 >= 0 && n2 <= 9)
		ret += printchar(n2 + '0');
	else
	{
		ret += printint(n2 / 10);
		ret += printint(n2 % 10);
	}
	return (ret);
}

int	printperc(void) //%%
{
	write(1, "%", 1);
	return (1);
}

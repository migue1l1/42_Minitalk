/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:30:23 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:30:30 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	flag2;
	int	c;

	ret = 0;
	flag2 = 1;
	c = 0;
	while (nptr[c] == 32 || (nptr[c] >= 9 && nptr[c] <= 13))
		c++;
	if (nptr[c] == '-' || nptr[c] == '+')
	{
		if (nptr[c] == '-')
			flag2 = -1;
		c++;
	}
	while (nptr[c] != '\0' && ft_isdigit(nptr[c]))
	{
		ret = ret * 10 + (nptr[c] - '0');
		c++;
	}
	return (ret * flag2);
}
/*
int	main(void)
{
	char *test1 = "  -435";
	printf("%d\n",ft_atoi(test1));
	return (0);
}*/

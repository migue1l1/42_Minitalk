/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:32:22 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 15:09:28 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	long	n2;
	int		c;

	if (n == 0)
		return (1);
	n2 = n;
	c = 0;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		c++;
	}
	if (n < 0)
		c++;
	return (c);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		c;
	long	n2;

	n2 = n;
	c = counter(n);
	ret = malloc(sizeof (char) * (counter(n) + 1));
	if (!ret)
		return (0);
	ret[c--] = '\0';
	if (n2 < 0)
	{
		ret[0] = '-';
		n2 = n2 * -1;
	}
	if (n2 == 0)
		ret[0] = '0';
	while (n2 != 0)
	{
		ret[c] = (n2 % 10) + '0';
		n2 = n2 / 10;
		c--;
	}
	return (ret);
}

/*int	main(void)
{
	int	test = -2147483648;
	printf("%s\n",ft_itoa(test));
	return (0);
}*/

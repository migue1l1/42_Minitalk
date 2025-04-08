/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:36:39 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 15:05:11 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	c;	

	if (!s)
		return ;
	c = 0;
	while (s[c] != '\0')
	{
		f(c, &s[c]);
		c++;
	}
}
/*
int	main(void)
{
	char	test1[5] = "1234";
	ft_striteri(test1,testfunc);
	printf("%s\n",test1);
	return (0);
}*/

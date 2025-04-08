/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:42:20 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:42:24 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (s1[c] == s2[c] && s1[c] != '\0' && c < n - 1)
	{
		c++;
	}
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
/*
int	main(void)
{
	char *test1 = "";
	char *test2 = "abc1";
	int i = 3;
	printf("%d\n",ft_strncmp(test1,test2,i));
	printf("%d\n",strncmp(test1,test2,i));
	return (0);
}*/

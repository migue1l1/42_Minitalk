/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:39:29 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/18 16:32:03 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = ft_strlen(src);
	if (size > s + 1)
	{
		while (i < s + 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (size != 0)
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[size - 1] = '\0';
	}
	return (s);
}
/*
int	main(void)
{
	char test1[6] = "aa123";
	char *test2 = "zzzz";
	char test1a[6] = "aa123";
	char *test2a = "zzzz";	
	printf("%d\n",ft_strlcpy(test1,test2,2));
	printf("%s\n",test1);
	printf("%d\n",strlcpy(test1a,test2a,2));
	printf("%s\n",test1a);
	return (0);
}*/

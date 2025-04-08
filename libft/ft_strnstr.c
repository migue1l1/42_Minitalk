/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:42:43 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 15:26:37 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = 0;
	if (need[0] == '\0' || hay == need)
		return ((char *)hay);
	while (c1 < len && hay[c1] != '\0')
	{
		c2 = 0;
		if (hay[c1] == need[c2])
		{
			while (((c1 + c2) < len) && (hay[c1 + c2] == need[c2]))
			{
				if (need[c2 + 1] == '\0')
					return ((char *) hay + c1);
				c2++;
			}
		}
		c1++;
	}
	return (0);
}
/*
int	main(void)
{
	char *test1 = "ha1ajhha88";
	char *test2 = "hha";
	printf("%s",ft_strnstr(test1,test2,15));
	return (0);
}*/

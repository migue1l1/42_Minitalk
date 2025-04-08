/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:33:25 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:33:28 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;
	size_t				i;

	if (!dest && !src)
		return (0);
	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned const char *)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return ((void *)dest);
}
/*
int	main(void)
{
	char	test1[4] = "abc1";
	char	*test2 = "aaaa";
	printf("%s\n",(char *)ft_memcpy((void *)test1, (const void *)test2,3));
	return (0);
}*/

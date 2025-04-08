/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:32:45 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:32:51 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*src;
	size_t				i;

	i = 0;
	src = s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *) src + i);
		i++;
	}
	return (NULL);
}

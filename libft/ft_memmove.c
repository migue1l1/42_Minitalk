/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:33:42 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:33:44 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*src1;
	unsigned char		*dest1;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest1 = dest;
	src1 = src;
	if (src1 < dest1 && dest1 < src1 + n)
	{
		i = n;
		while (i-- > 0)
			dest1[i] = src1[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}

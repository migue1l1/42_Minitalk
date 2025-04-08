/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:43:02 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/01 19:43:05 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == (unsigned char)c)
		return (str + i);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i--;
	}
	return (0);
}

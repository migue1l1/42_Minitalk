/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:37:40 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 15:25:53 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <strings.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		c1;
	int		c2;
	int		c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	if (!s1 && !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	while (s1[c1] != '\0')
	{
		ret[c3] = s1[c1];
		c1++;
		c3++;
	}
	while (s2[c2] != '\0')
		ret[c3++] = s2[c2++];
	ret[c3] = '\0';
	return (ret);
}
/*
int	main(void)
{
	char	*test1 = "abc";
	char	*test1b = "abc";
	char	*test2 = "123\n";
	char	*test2b = "123\n";
	printf("%s\n",ft_strjoin(test1,test2));
	printf("%s\n",strjoin(test1b,test2b));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:41:41 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 15:17:11 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		c;	

	c = 0;
	ret = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (0);
	while (s[c] != '\0')
	{
		ret[c] = f(c, s[c]);
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
/*char	tempfunc(unsigned int move, char chr)
{
	return (chr + move);

}
int	main(void)
{
	char	test1[5] = "1234";
	printf("%s\n",ft_strmapi(test1,tempfunc));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:35:47 by pde-cast          #+#    #+#             */
/*   Updated: 2024/11/05 22:09:06 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*writew(const char *str, int start, int end)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc((end - start + 1) * sizeof(char));
	if (!w)
		return (NULL);
	while (start < end)
	{
		w[i] = str[start];
		i++;
		start++;
	}
	w[i] = 0;
	return (w);
}

static void	*fre(char **s, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	word_count(const char *str, char c)
{
	int	counter;
	int	x;
	int	i;

	counter = 0;
	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && x == 0)
		{
			x = 1;
			counter++;
		}
		else if (str[i] == c)
			x = 0;
		i++;
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	int		j;
	int		w;

	i = -1;
	j = -1;
	w = -1;
	ret = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && w < 0)
			w = i;
		else if ((s[i] == c || i == ft_strlen(s)) && w >= 0)
		{
			ret[++j] = writew(s, w, i);
			if (!(ret[j]))
				return (fre(ret, j));
			w = -1;
		}
	}
	return (ret);
}
/*
int	main(void)
{
	const char *test1 = "aaa-bb-v-c-d";
	char test2 = '-';
	printf("%d\n",ft_split(test1,test2[1]));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:48:45 by pde-cast          #+#    #+#             */
/*   Updated: 2025/04/08 22:26:48 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

char	*ft_strjoin2(char const *s1, char s2)
{
	char	*ret;
	int		c1;
	int		c3;

	c1 = -1;
	c3 = -1;
	if (!s1 && !s2)
		return (NULL);
	ret = ft_calloc(sizeof(char) , (ft_strlen(s1) + 4));
	if (!ret)
		return (NULL);
	while (s1[++c1] != '\0')
	{
		ret[++c3] = s1[c1];
	}

	ret[++c3] = s2;
	if(s2 == '\0')
	{
		ft_printf("%s\n", ret);
		free(ret);
		return NULL;
	}
	return (ret);
}

void	bit_handler(int signal)
{
	static char	i = '\0';
	static int	bit;
	static char	*message = NULL;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (!message)
			message = ft_calloc(1, sizeof(char) + 1);
		message = ft_strjoin2(message, i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for message\n");
	while (argc == 1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause ();
	}
	return (0);
}

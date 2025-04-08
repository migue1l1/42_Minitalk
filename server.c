/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:48:45 by pde-cast          #+#    #+#             */
/*   Updated: 2025/04/07 17:57:15 by pde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

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
			message = malloc(1);
		message = ft_strjoin(message, &i);
		if (i == '\0')
		{
			usleep(2);
			ft_printf("%s", message);
			ft_printf("%c", '\n');
			ft_memset(message, 0, ft_strlen(message));
			//free(message);
		}
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

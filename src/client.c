/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:43:59 by riolivei          #+#    #+#             */
/*   Updated: 2022/12/11 15:48:21 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Invalid number of params");
		exit(0);
	}
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("Incorrect PID!");
			exit(0);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message!");
		exit(0);
	}
}

void	send_msg(int pid, char *msg)
{
	char	c;
	int		bits;

	while (*msg)
	{
		c = *msg;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Character received!\n");
}

void	config_signals(void)
{
	struct sigaction	new_sig;

	new_sig.sa_handler = &sig_handler;
	new_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new_sig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
}

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	config_signals();
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}

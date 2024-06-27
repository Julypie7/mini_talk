/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:58:06 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/27 15:24:28 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handl_sigusr1(char *string, int *i, int *bit, siginfo_t *siginfo)
{
	if (string[*i] & (1 << *bit))
	{
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
		{
			write(2, "Error!\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
		{
			write(2, "Error!\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	(*bit)++;
	if (*bit == 8)
	{
		(*i)++;
		*bit = 0;
	}
}

static void	handl(int signum, siginfo_t *siginfo, void *context)
{
	static int	i;
	static int	bit = 1;
	static char	*string;

	if (signum == 2147483647)
	{
		string = context;
		return ;
	}
	if (signum == SIGUSR1)
	{
		handl_sigusr1(string, &i, &bit, siginfo);
	}
	else
	{
		exit(0);
	}
}

void	send_signal(int pid, char signal)
{
	int	sig;

	if (signal & (1 << 0))
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
	{
		write(2, "Error!\n", 7);
		exit(EXIT_FAILURE);
	}
}

void	setup_signal_handling(char *argv)
{
	struct sigaction	sigac;
	sigset_t			sigset;

	handl(2147483647, NULL, argv);
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sigac.sa_mask = sigset;
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = handl;
	if (sigaction(SIGUSR1, &sigac, NULL) == -1)
	{
		write(2, "Error!\n", 7);
		return ;
	}
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
	{
		write(2, "Error!\n", 7);
		return ;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || check_digit(argv[1]) == 0 || ft_strlen(argv[2]) == 0)
		return (write(2, "incorrect arguments\n", 20));
	else
	{
		pid = ft_atoi(argv[1]);
		send_signal(pid, argv[2][0]);
	}
	setup_signal_handling(argv[2]);
	while (1)
		pause();
}

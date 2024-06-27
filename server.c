/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:46:02 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/27 15:10:16 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*connect(char *str, unsigned char c)
{
	char		*str2;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(str);
	str2 = (char *)malloc(sizeof(char) * (len + 2));
	if (!str2)
	{
		free(str);
		return (NULL);
	}
	while (i < len && str)
	{
		str2[i] = str[i];
		i++;
	}
	if (i == len)
	{
		str2[i++] = c;
	}
	str2[i] = '\0';
	free (str);
	return (str2);
}

static void	handl(int signum, siginfo_t *siginfo, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static char				*str = NULL;

	(void)context;
	if (signum == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit != 8 || (bit == 8 && c != '\0'))
		kill(siginfo->si_pid, SIGUSR1);
	if (bit == 8)
	{
		if (c != '\0')
			str = connect(str, c);
		else
		{
			str = str2(str);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigac;
	int					pid;
	sigset_t			sigset;

	pid = getpid();
	if (!pid)
		write(1, "Pid doesn't exist", 17);
	else
	{
		write(1, "Server PID is: ", 15);
		ft_putnbr(pid);
		write(1, "\n", 1);
	}
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sigac.sa_mask = sigset;
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = handl;
	if (sigaction(SIGUSR1, &sigac, NULL) == -1)
		return (write(2, "Error!\n", 7));
	if (sigaction(SIGUSR2, &sigac, NULL) == -1)
		return (write(2, "Error!\n", 7));
	while (1)
		pause();
}

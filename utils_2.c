/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:18:57 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/27 15:22:36 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	err_msg(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	exit(EXIT_FAILURE);
}

char	*str2(char *s)
{
	static char	*str;

	if (s != NULL)
	{
		write_msg(s);
		free(s);
		s = NULL;
		str = s;
	}
	return (str);
}

void	write_msg(char *str)
{
	static int	i;

	i = ft_strlen(str);
	write (1, str, i);
	i = 0;
}

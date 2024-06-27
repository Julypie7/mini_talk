/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:48:50 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/27 15:23:36 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
int		check_digit(char *str);
void	ft_putnbr(int num);
int		err_msg(char *str);
char	*str2(char *s);
void	write_msg(char *str);

#endif

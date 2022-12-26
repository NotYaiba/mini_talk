/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:07:26 by melkarmi          #+#    #+#             */
/*   Updated: 2021/07/06 17:37:11 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigint(int sig)
{
	static unsigned char	decimal;
	static char				i;

	decimal += (sig == SIGUSR1) << i;
	i++;
	if (i > 7)
	{
		decimal = reverse_bits(decimal);
		i = 0;
		write(1, &decimal, 1);
		decimal = 0;
		return ;
	}
}

void	my_sig(void)
{
	if (signal(SIGUSR1, handle_sigint) == SIG_ERR)
	{
		ft_putstr_fd("Error.\n", 2);
		exit(0);
	}
	if (signal(SIGUSR2, handle_sigint) == SIG_ERR)
	{
		ft_putstr_fd("Error.\n", 2);
		exit(0);
	}
}

int	ft_isdigit(int cc)
{
	if (cc >= 48 && cc <= 57)
		return (1);
	return (0);
}

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	if (pid[0] == '-')
		return (0);
	if (pid[0] == '+')
		i++;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	decimal_to_binary(int n, char **av)
{
	int	c;
	int	d;
	int	t;
	int	err;

	t = 0;
	c = 8;
	while (c--)
	{
		usleep(150);
		d = n >> c;
		if (d & 1)
			err = kill(atoi(av[1]), SIGUSR1);
		else
			err = kill(atoi(av[1]), SIGUSR2);
		if (err == -1)
		{
			ft_putstr_fd("Error.\n", 2);
			exit(0);
		}
		t++;
	}
}

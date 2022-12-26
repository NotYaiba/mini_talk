/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:01:25 by melkarmi          #+#    #+#             */
/*   Updated: 2021/07/06 16:05:55 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(fd, &c[i], 1);
		i++;
	}
}

unsigned char	reverse_bits(unsigned char b)
{
	unsigned char	r;
	unsigned int	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	r;
	int				a;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		r = n * -1;
	}
	else
		r = n;
	if (r >= 10)
		ft_putnbr_fd(r / 10, fd);
	a = r % 10 + 48;
	ft_putchar_fd(a, fd);
}

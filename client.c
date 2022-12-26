/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:24:46 by melkarmi          #+#    #+#             */
/*   Updated: 2021/07/06 17:44:57 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3 || check_pid(av[1]) == 0)
	{
		ft_putstr_fd("Error.\n", 2);
		return (0);
	}
	while (av[2][i])
	{
		decimal_to_binary((int)av[2][i], av);
		i++;
	}
	decimal_to_binary(10, av);
	return (0);
}

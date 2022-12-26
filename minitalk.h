/* ************************************************************************** */
/*	                                                                         */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:20:24 by melkarmi          #+#    #+#             */
/*   Updated: 2021/07/06 16:10:23 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include	<stdlib.h>
# include	<sys/types.h>
# include	<unistd.h>
# include	<signal.h>
# include	<math.h>
# include <string.h>
# include	<stdio.h>

void			decimal_to_binary(int n, char **av);
int				ft_strlen(char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *c, int fd);
unsigned char	reverse_bits(unsigned char b);
void			ft_putnbr_fd(int n, int fd);
void			my_sig(void);
int				ft_isdigit(int cc);
int				check_pid(char *pid);
void			handle_sigint(int sig);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:05:46 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/04 17:03:49 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client.h"

void	ft_send_bit(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	ft_send_int(pid_t pid, int nb)
{
	int	i;

	i = 32;
	while (i--)
		ft_send_bit(pid, (nb >> i) & 1);
}

void	ft_send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
		ft_send_bit(pid, (c >> i) & 1);
}

void	ft_send_msg(pid_t pid, char *msg)
{
	ft_send_int(pid, ft_strlen(msg));
	while (*msg)
		ft_send_char(pid, *msg++);
	usleep(200);
	ft_send_char(pid, 0);
}

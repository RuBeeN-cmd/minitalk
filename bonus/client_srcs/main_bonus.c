/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:52:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/14 13:16:16 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client_bonus.h"

t_info	g_info;

void	ft_send_current_bit(void)
{
	if ((g_info.str[g_info.index] >> g_info.shift) & 1)
		kill(g_info.srv_pid, SIGUSR1);
	else
		kill(g_info.srv_pid, SIGUSR2);
	if (!g_info.shift)
	{
		g_info.index++;
		g_info.shift = 7;
	}
	else
		g_info.shift--;
}

void	ft_msg_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr_fd("Recu\n", 1);
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGUSR2)
		ft_send_current_bit();
	else
		exit(EXIT_FAILURE);
}

void	ft_send_len_current_bit(void)
{
	if ((ft_strlen(g_info.str) >> g_info.shift) & 1)
		kill(g_info.srv_pid, SIGUSR1);
	else
		kill(g_info.srv_pid, SIGUSR2);
	if (!g_info.shift)
	{
		g_info.shift = 7;
		signal(SIGUSR1, ft_msg_handler);
		signal(SIGUSR2, ft_msg_handler);
	}
	else
		g_info.shift--;
}

void	ft_len_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_send_len_current_bit();
	else
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	g_info = ft_parse_input(argc, argv);
	if (!ft_strlen(g_info.str) || g_info.srv_pid == -1)
		exit(EXIT_FAILURE);
	signal(SIGUSR2, ft_len_handler);
	ft_send_len_current_bit();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

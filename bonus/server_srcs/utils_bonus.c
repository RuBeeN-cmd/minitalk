/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:05:07 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/14 13:15:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"server_bonus.h"

void	ft_set_action(void)
{
	struct sigaction	act;

	act.sa_sigaction = sig_action;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	ft_print_pid(void)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	ft_end_procedure(char **str, int *size, int *i)
{
	free(*str);
	*str = NULL;
	*size = 0;
	*i = 0;
}

void	ft_add_bit_to_size(int bit, int *size, char **str)
{
	static int	shift = 32;

	if (shift--)
		*size += bit << shift;
	if (!shift)
	{
		*str = ft_calloc(*size, sizeof(char));
		shift = 32;
	}
}

void	ft_reset_shift(int *shift, int *i)
{
	if (!(*shift))
	{
		(*i)++;
		*shift = 8;
	}
}

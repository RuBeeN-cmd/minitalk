/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:52:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/14 13:36:52 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"server_bonus.h"

void	ft_add_bit_to_str(int *shift, int *i, int bit, char *c)
{
	(*shift)--;
	*c += bit << *shift;
	ft_reset_shift(shift, i);
}

void	ft_end_msg(int *size, int *i, pid_t pid, char **str)
{
	write(1, *str, *size);
	ft_end_procedure(str, size, i);
	kill(pid, SIGUSR1);
}

void	sig_action(int signum, siginfo_t *info, void *context)
{
	static char	*str = NULL;
	static int	shift = 8;
	static int	size = 0;
	static int	i = 0;
	int			bit;

	(void) context;
	bit = signum == SIGUSR1;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		ft_end_procedure(&str, &size, &i);
	if (!str)
		ft_add_bit_to_size(bit, &size, &str);
	else
	{
		ft_add_bit_to_str(&shift, &i, bit, &(str[i]));
		if (i == size)
		{
			ft_end_msg(&size, &i, info->si_pid, &str);
			return ;
		}
	}
	if (signum == SIGUSR1 || signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	ft_set_action();
	ft_print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

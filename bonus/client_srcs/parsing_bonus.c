/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:59:08 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/14 13:16:20 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client_bonus.h"

t_info	ft_parse_input(int argc, char **argv)
{
	t_info	info;

	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client PID message\n", 1);
		exit(EXIT_FAILURE);
	}
	info.srv_pid = ft_atoi(argv[1]);
	info.str = argv[2];
	info.index = 0;
	info.shift = 31;
	return (info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:59:18 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/06 14:16:40 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include"libft.h"
# include<sys/types.h>
# include<unistd.h>
# include<signal.h>

typedef struct s_info
{
	char	*str;
	pid_t	srv_pid;
	int		index;
	int		shift;
}				t_info;

// main.c
void	action(int signum);

// parsing.c
t_info	ft_parse_input(int argc, char **argv);

// send.c
void	ft_send_bit(pid_t pid, int bit);
void	ft_send_int(pid_t pid, int nb);
void	ft_send_char(pid_t pid, char c);
void	ft_send_msg(pid_t pid, char *msg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:59:18 by rrollin           #+#    #+#             */
/*   Updated: 2022/06/08 13:58:09 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include"libft.h"
# include<sys/types.h>
# include<unistd.h>
# include<signal.h>

// main.c
void	ft_add_bit_to_str(int *shift, int *i, int bit, char *c);
void	ft_end_msg(int *size, int *i, pid_t pid, char **str);
void	sig_action(int signum, siginfo_t *info, void *context);

// utils.c
void	ft_set_action(void);
void	ft_print_pid(void);
void	ft_end_procedure(char **str, int *size, int *i);
void	ft_add_bit_to_size(int bit, int *size, char **str);
void	ft_reset_shift(int *shift, int *i);

#endif
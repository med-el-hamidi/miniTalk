/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:43:58 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/06 19:44:36 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <limits.h>

void	exit_failure(char *msg);
void	handle_input(char *nbr);
void	_signal(int signum, void *handler);
void	_kill(pid_t pid, int signum);
#endif

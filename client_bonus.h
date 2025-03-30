/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:39:50 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/10 21:39:52 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <limits.h>

void	exit_failure(char *msg);
void	handle_input(char *nbr);
void	_signal(int signum, void *handler);
void	_kill(pid_t pid, int signum);
#endif

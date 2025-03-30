/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:40:33 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/10 21:40:35 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <limits.h>

static void	_signal(int signum, void *handler);
static int	unicode_checker(unsigned char c);
static void	unicode_handler(pid_t *client_pid, char c, int *idx, int *bit);
static void	handler(int signum, siginfo_t *info, void *context);
#endif

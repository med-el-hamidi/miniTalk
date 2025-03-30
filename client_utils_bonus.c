/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:40:00 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/10 21:40:01 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	exit_failure(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	_signal(int signum, void *handler)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	if (sigaction(signum, &sa, NULL) == -1)
		exit_failure("\nsigaction failed!\n");
}

void	_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		if (kill(pid, 0) == -1)
		{
			ft_putstr_fd("\nThe server PID ", 2);
			ft_putnbr_base_fd(pid, DECIMAL_BASE, 2);
			ft_putstr_fd(" is invalid!\n", 2);
		}
		else
			ft_putstr_fd("\nkill failed!\n", 2);
		exit(EXIT_FAILURE);
	}
}

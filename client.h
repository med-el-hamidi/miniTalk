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

#ifndef SERVER_H
# define SERVER_H
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <limits.h>

static void	_signal(int signum, void *handler);
static void	char_handler(pid_t *client_pid, char c, int *bit);
static void	handler(int signum, siginfo_t *info, void *context);
#endif

#ifndef SERVER_H
#define SERVER_H
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <error.h>
# include <limits.h>

void	Signal(int signum, void *handler);
void	Kill(pid_t pid, int signum);
#endif

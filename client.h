#ifndef CLIENT_H
#define CLIENT_H
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <error.h>
# include <limits.h>

void	handle_input(char *nbr);
void	Signal(int signum, void *handler);
void	Kill(pid_t pid, int signum);
#endif

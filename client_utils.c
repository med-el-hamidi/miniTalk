#include "client.h"

void	Signal(int signum, void *handler)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	if (sigaction(signum, &sa, NULL) == -1)
	{
		ft_printf("sigaction failed!\n");
		exit(EXIT_FAILURE);
	}
}

void	Kill(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		if (kill(pid, 0) == -1)
			ft_printf("The server PID %d is invalid!\n", pid);
		else
			ft_printf("kill failed!\n");
		exit(EXIT_FAILURE);
	}
}

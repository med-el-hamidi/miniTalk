#include "server.h"

static void	handler(int signum, siginfo_t *info, void *extra_info);

int	main(void)
{
	int	ret;

	ft_printf("Process ID: %d\n", getpid());
	
	Signal(SIGUSR1, handler);
	Signal(SIGUSR2, handler);

	while (1)
	{
		ret = pause();
		if (!ret)
		{
			ft_printf("The server has been terminated!\n");
			exit(EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}

static void	handler(int signum, siginfo_t *info, void *extra_info)
{
	static char	c = 0;
	static int	bit = 0;
	static pid_t	client_pid;

	(void)extra_info;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (signum == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	++bit;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (!c)
		{
			ft_printf("\n");
			Kill(client_pid, SIGUSR2);
			return ;
		}
		ft_printf("%c", c);
	}
	Kill(client_pid, SIGUSR1);
}

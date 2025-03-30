#include "server.h"

int	main(void)
{
	ft_printf("Process ID: ->->-> %d <-<-<-\n", getpid());
	_signal(SIGUSR1, handler);
	_signal(SIGUSR2, handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

static void	_signal(int signum, void *handler)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	if (sigaction(signum, &sa, NULL) == -1)
	{
		ft_putstr_fd("\nsigaction failed!\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	char_handler(pid_t *client_pid, char c, int *bit)
{
	if (*bit == CHAR_BIT)
	{
		*bit = 0;
		if (c == '\0')
		{
			kill(*client_pid, SIGUSR1);
			return ;
		}
		ft_printf("%c", c);
	}
	kill(*client_pid, SIGUSR1);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (client_pid == 0 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}
	if (signum == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (signum == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	bit++;
	char_handler(&client_pid, c, &bit);
}

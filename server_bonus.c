#include "server_bonus.h"

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

static int	unicode_checker(unsigned char c)
{
	if (c < 0b10000000)
		return (1);
	else if ((c & 0b11100000) == 0b11000000)
		return (2);
	else if ((c & 0b11110000) == 0b11100000)
		return (3);
	else if ((c & 0b11111000) == 0b11110000)
		return (4);
	return (0);
}

static void	unicode_handler(pid_t *client_pid, char c, int *idx, int *bit)
{
	static unsigned char	unicode[6];
	static int				nbr = 0;

	if (*bit == CHAR_BIT)
	{
		*bit = 0;
		if (*idx == 0)
			nbr = unicode_checker(c);
		unicode[(*idx)++] = c;
		if (--nbr == 0)
		{
			unicode[*idx] = '\0';
			ft_printf("%s", unicode);
			*idx = 0;
		}
		if (c == '\0')
		{
			kill(*client_pid, SIGUSR2);
			return ;
		}
	}
	kill(*client_pid, SIGUSR1);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		bit = 0;
	static int		idx = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (client_pid == 0 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		idx = 0;
		c = 0;
		bit = 0;
	}
	if (signum == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (signum == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	bit++;
	unicode_handler(&client_pid, c, &idx, &bit);
}

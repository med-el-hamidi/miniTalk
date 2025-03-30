#include "client_bonus.h"

static void	send(pid_t pid, char c);
static void	ack_handler(int signum);
static void	end_handler(int signum);

volatile sig_atomic_t	g_proceed = 0;

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
		exit_failure("INVALID_INPUT: ./client_bonus <SERVER_PID> <\"MESSAGE\">\n");
	handle_input(av[1]);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		exit_failure("INVALID_PID: ./client_bonus <SERVER_PID> <\"MESSAGE\">\n");
	message = av[2];
	if (*message == '\0')
		exit_failure("EMPTY_MESSAGE: ./client_bonus <SERVER_PID> <\"MESSAGE\">\n");
	_signal(SIGUSR1, ack_handler);
	_signal(SIGUSR2, end_handler);
	while (*message)
		send(server_pid, *message++);
	send(server_pid, '\0');
	return (EXIT_SUCCESS);
}

static void	send(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0b10000000 >> bit))
			_kill(pid, SIGUSR1);
		else
			_kill(pid, SIGUSR2);
		++bit;
		while (!g_proceed)
			usleep(1);
		g_proceed = 0;
	}
}

static void	ack_handler(int signum)
{
	(void)signum;
	g_proceed = 1;
}

static void	end_handler(int signum)
{
	(void)signum;
	ft_printf("\n->->-> Message delivered successfully! <-<-<-\n");
	exit(EXIT_SUCCESS);
}

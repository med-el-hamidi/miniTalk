#include "client.h"

static void	send(pid_t pid, char c);
static void	ack_handler(int signum);
static void	end_handler(int signum);

volatile sig_atomic_t	status = 0;

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("INVALID_INPUT: ./client <PID> <\"MESSAGE\">\n");
		exit(EXIT_FAILURE);
	}
	handle_input(av[1]);
	server_pid = ft_atoi(av[1]);
	message = av[2];
	Signal(SIGUSR1, ack_handler);
	Signal(SIGUSR2, end_handler);
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
			Kill(pid, SIGUSR1);
		else
			Kill(pid, SIGUSR2);
		++bit;
		if (!status)
			usleep(10);
		status = 0;
	}
}

static void	ack_handler(int signum)
{
	(void)signum;
	status = 1;
}

static void	end_handler(int signum)
{
	(void)signum;
	ft_printf("ACK!\n");
	exit(EXIT_SUCCESS);
}

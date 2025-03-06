#include "minitalk.h"

int		g_status = 0;

void	usr1_action(int sig)
{
	(void)sig;
	g_status = 1;
}

void	send_bits(pid_t server_pid, char byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_status = 0;
		if (byte & (1 << (7 - i)))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_status == 0)
			usleep(80);
		++i;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	new_usr1;
	pid_t				server_pid;
	char				*str;

	if (argc != 3)
		return (ft_putstr_fd("Usage ./client <server pid> <message>\n", 1), 1);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	sigemptyset(&new_usr1.sa_mask);
	new_usr1.sa_handler = usr1_action;
	new_usr1.sa_flags = 0;
	sigaction(SIGUSR1, &new_usr1, NULL);
	while (str && *str != '\0')
	{
		send_bits(server_pid, *str);
		str++;
	}
}

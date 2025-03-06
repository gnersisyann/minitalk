#include "minitalk.h"

int		g_status = 0;

void	usr1_action(int sig)
{
	(void)sig;
	g_status = 1;
}

void	usr2_action(int sig)
{
	(void)sig;
	ft_putstr_fd("Message has been sent\n", 1);
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
	struct sigaction	new_usr2;
	pid_t				server_pid;
	char				*str;

	if (argc != 3)
		return (ft_putstr_fd("Usage ./client_bonus <server pid> <message>\n",
				1), 1);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	sigemptyset(&new_usr1.sa_mask);
	new_usr1.sa_handler = usr1_action;
	new_usr1.sa_flags = 0;
	sigaction(SIGUSR1, &new_usr1, NULL);
	sigemptyset(&new_usr2.sa_mask);
	new_usr2.sa_handler = usr2_action;
	new_usr2.sa_flags = 0;
	sigaction(SIGUSR2, &new_usr2, NULL);
	while (str && *str != '\0')
	{
		send_bits(server_pid, *str);
		str++;
	}
	send_bits(server_pid, '\0');
}

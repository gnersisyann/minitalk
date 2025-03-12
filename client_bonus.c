#include "minitalk.h"

int		g_status = 0;

void	usr2_action(int sig)
{
	(void)sig;
	ft_putstr_fd("Message has been sent!\n", 1);
}

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
		{
			usleep(100);
			kill(server_pid, SIGUSR1);
		}
		else
		{
			usleep(100);
			kill(server_pid, SIGUSR2);
		}
		i++;
		while (g_status == 0)
			usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
		return (ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 1), 1);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	signal(SIGUSR1, usr1_action);
	signal(SIGUSR2, usr2_action);
	while (*str)
		send_bits(server_pid, *str++);
	send_bits(server_pid, '\0');
	return (0);
}

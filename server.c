#include "minitalk.h"

t_data	g_data = {0, 0};

void	add_bit(int bit)
{
	if (bit == 1)
		g_data.current_char |= (1 << (7 - g_data.bit_pos));
	g_data.bit_pos++;
}

void	check_char(void)
{
	if (g_data.bit_pos == 8)
	{
		write(1, &g_data.current_char, 1);
		g_data.current_char = 0;
		g_data.bit_pos = 0;
	}
}

void	usr1_action(int signum, siginfo_t *info, void *extra_info)
{
	(void)signum;
	(void)extra_info;
	add_bit(1);
	check_char();
	kill(info->si_pid, SIGUSR1);
}

void	usr2_action(int signum, siginfo_t *info, void *extra_info)
{
	(void)signum;
	(void)extra_info;
	add_bit(0);
	check_char();
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	new_usr1;
	struct sigaction	new_usr2;

	pid = getpid();
	ft_putstr_fd("Server started, server pid is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	new_usr1.sa_sigaction = usr1_action;
	sigemptyset(&new_usr1.sa_mask);
	new_usr1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &new_usr1, NULL);
	new_usr2.sa_sigaction = usr2_action;
	sigemptyset(&new_usr2.sa_mask);
	new_usr2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &new_usr2, NULL);
	while (1)
		pause();
}

#include "minitalk.h"

void	add_bit(int bit, int *bit_pos, char *current_char)
{
	if (bit == 1)
		*current_char |= (1 << (7 - *bit_pos));
	(*bit_pos)++;
}

void	check_char(int *bit_pos, char *current_char, pid_t client_pid)
{
	if (*bit_pos == 8)
	{
		write(1, current_char, 1);
		if (*current_char == '\0')
		{
			if (kill(client_pid, SIGUSR2) == -1)
				handle_error("Error sending SIGUSR2");
		}
		*current_char = 0;
		*bit_pos = 0;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *extra_info)
{
	static int	bit_pos = 0;
	static char	current_char = 0;

	(void)extra_info;
	if (signum == SIGUSR1)
		add_bit(1, &bit_pos, &current_char);
	else if (signum == SIGUSR2)
		add_bit(0, &bit_pos, &current_char);
	check_char(&bit_pos, &current_char, info->si_pid);
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_error("Error sending SIGUSR1");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("Server started, server pid is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) \
				== -1)
		handle_error("Error setting up signal handler");
	while (1)
		pause();
}

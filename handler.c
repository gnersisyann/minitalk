#include "minitalk.h"

void	handle_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

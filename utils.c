#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	write(fd, s, size);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	negative;

	negative = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}

static size_t	digitcount(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	case_handler(int *n, int *fd)
{
	if (*n == 0)
	{
		write(*fd, "0", 1);
		return ;
	}
	if (*n == -2147483648)
	{
		write(*fd, "-2147483648", 11);
		return ;
	}
	if (*n < 0)
	{
		write(*fd, "-", 1);
		*n *= -1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	size_t	digits;
	size_t	i;
	size_t	tmp;

	case_handler(&n, &fd);
	if (n == 0 || n == -2147483648)
		return ;
	digits = digitcount(n);
	tmp = digits;
	i = 1;
	while (--tmp)
		i *= 10;
	while (n || digits)
	{
		c = (n / i) + '0';
		write(fd, &c, 1);
		n %= i;
		i /= 10;
		digits--;
	}
}

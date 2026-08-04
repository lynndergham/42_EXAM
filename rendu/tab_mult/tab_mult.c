#include <unistd.h>

void	putnbr(int n)
{
	char c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	n;
	int	i;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	n = 0;
	i = 0;
	while (av[1][i])
		n = n * 10 + av[1][i++] - '0';
	i = 1;
	while (i <= 9)
	{
		putnbr(i);
		write(1, " x ", 3);
		putnbr(n);
		write(1, " = ", 3);
		putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
}
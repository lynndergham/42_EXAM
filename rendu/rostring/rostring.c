#include <unistd.h>

void	put(char *s, int a, int b)
{
	while (a < b)
		write(1, &s[a++], 1);
}

int	main(int ac, char **av)
{
	int	i = 0;
	int	start;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	start = i;
	while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		i++;
	while (av[1][i])
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		if (av[1][i])
			write(1, " ", 1);
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			write(1, &av[1][i++], 1);
	}
	if (i > start)
	{
		write(1, " ", 1);
		put(av[1], start, i);
	}
	write(1, "\n", 1);
}
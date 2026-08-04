#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_word(char *s)
{
	int	i = 0;

	while (s[i] && !is_space(s[i]))
		write(1, &s[i++], 1);
}

int	main(int ac, char **av)
{
	int	i = 0;
	int	start;

	if (ac != 2)
		return (write(1, "\n", 1), 0);

	while (is_space(av[1][i]))
		i++;
	start = i;

	while (av[1][i] && !is_space(av[1][i]))
		i++;

	if (!av[1][i])
	{
		print_word(av[1] + start);
		write(1, "\n", 1);
		return (0);
	}

	while (is_space(av[1][i]))
		i++;

	while (av[1][i])
	{
		if (is_space(av[1][i]))
		{
			write(1, " ", 1);
			while (is_space(av[1][i]))
				i++;
		}
		else
			write(1, &av[1][i++], 1);
	}

	write(1, " ", 1);
	print_word(av[1] + start);
	write(1, "\n", 1);
}
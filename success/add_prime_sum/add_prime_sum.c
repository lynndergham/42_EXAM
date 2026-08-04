#include <unistd.h>

int	main(int ac, char **av)
{
	int n = 0;
	int i = 2;
	int j;
	int sum = 0;

	if (ac != 2)
		return (write(1, "0\n", 2), 0);

	while (av[1][n])
		n = n * 10 + av[1][n++] - '0';

	while (i <= n)
	{
		j = 2;
		while (j < i && i % j)
			j++;
		if (j == i)
			sum += i;
		i++;
	}

	if (sum >= 10)
		main(2, (char *[]){av[0], "0"});
	
}
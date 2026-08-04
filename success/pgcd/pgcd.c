#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	tmp;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (b != 0)
		{
			tmp = a % b;
			a = b;
			b = tmp;
		}
		printf("%d\n", a);
	}
	else
		printf("\n");
	return (0);
}
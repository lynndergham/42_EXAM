#include <unistd.h>
int	ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return(len);
}
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_strlen("Hello"));
	return (0);
}
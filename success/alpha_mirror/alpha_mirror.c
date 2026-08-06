#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int do_op(int a, char op, int b)
{
    int res = 0;

    if(op == '*')
        res = a * b;
    else if(op == '+')
        res = a + b;
    else if(op == '-')
        res = a - b;
    else if(op == '/')
        res = a/ b;
    else if(op == '%')
        res = a % b;
    return(res);
}
int main(int ac, char **av)
{
    if(ac == 4)
        printf("%i",do_op( atoi(av[1]), av[2][0] , atoi(av[3])));
    print("\n");
}
#include <unisd.h>

void put_nbr(int n)
{
    char c;

    if(n >= 10)
        put_nbr(n/10);
    c = n % 10 + '0';
    write(1,&c,1);
}

int main(int ac, char **av)
{
    (void)av;
    put_nbr(ac - 1);
    write(1,"\n",1);
}
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    char res;
    while(ac == 2)
    {
        if(av[1][i] >= 'a' && av[1][i] <= 'z')
            res = 'z' - (c - 'a');

        if(av[1][i] >= 'A' && av[1][i] <= 'A')
            res = 'Z' - (c - 'A');

        write(1,&res,1);
        i++;
    }
    write(1, "\n",1);
}
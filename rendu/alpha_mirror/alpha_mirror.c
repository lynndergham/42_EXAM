#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    char res;
    while(ac == 2)
    {
        res = av[1][i];

        if(res >= 'a' && res <= 'z')
            res = 'z' - (res - 'a');

        if(res >= 'A' &&res <= 'A')
            res = 'Z' - (res - 'A');

        write(1,&res,1);
        i++;
    }
    write(1, "\n",1);
}
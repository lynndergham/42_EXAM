#include <unistd.h>
int main(int ac, char **av)
{
    int i = 0;
    char c;

    if(ac == 2)
    {
        c = av[1][i];

        while(av[1][i])
        {
            if(c >= 'a' && c <= 'z')
                c = z -(c - 'a');
            else if(c >= 'A' && c <= 'Z')
                c = z - (c - 'A');
            write(1,&c,1);
            i++;
        }

    }
    write(1,"\n",1);
}
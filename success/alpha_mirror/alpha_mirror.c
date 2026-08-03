#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    char res;
    if(ac == 2)
    {
        while(av[1][i])
        {
        res = av[1][i];

        if(res >= 'a' && res <= 'z')
            res = 'z' - (res - 'a');

        if(res >= 'A' &&res <= 'Z')
            res = 'Z' - (res - 'A');

        write(1,&res,1);
        i++; 
        }
       
    }
     write(1, "\n",1);
    
}
#include <unistd.h>
int main( int argc, char **argv)
{
    int i = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            char c;
            c = argv[1][i];
            if (c >= 'A' && c <= 'Y')
                c = c + 1;
            else if ( c >= 'a' && c <= 'y')
                c = c + 1;
            else if ( c == 'Z')
                c = 'A';
            else if ( c == 'z')
                c = 'a';
            write(1, &c,1);
            i++;
        }
    }
    write(1, "\n",1);
    return (0);
}
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{

    int i = 1;
    int r;

    while (i < 200)
    {
        r = i & 1;
        printf("%d || %d \n", r, i);
        i++;
    }
    return (0);
}
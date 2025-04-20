#include <stdio.h>

int fat (int n);

int main (void)
{
    int n = 5;
    int r;
    r = fat(n);
    printf("Fatorial de %d = %d\n", n, r);
    return 0;
}

int fat (int n)
{
    int f = 1;
    while (n != 0)
    {
        f *= n;
        n--;
    }
    return f;
}

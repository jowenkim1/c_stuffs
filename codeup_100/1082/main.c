#include <stdio.h>

int main(void)
{
    int x;
    scanf("%X", &x);
    for (int i = 1; i < 16; i++)
    {
        printf("%X*%X=%X\n", x, i, x * i);
    }
}
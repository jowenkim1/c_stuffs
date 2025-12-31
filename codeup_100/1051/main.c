#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    if (a <= b)
    {
        c = 1;
    }
    else
    {
        c = 0;
    }
    printf("%d", c);
}
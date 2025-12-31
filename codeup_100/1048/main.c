#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int mul = 1;
    for (int i = 0; i < b; i++)
    {
        mul *= 2;
    }
    printf("%d\n", a * mul);
}
#include <stdio.h>

int main(void)
{
    int x;

    scanf("%d", &x);
    for (int i = 1; i < x + 1; i++)
    {
        if (i % 3)
        {
            printf("%d ", i);
        }
    }
}
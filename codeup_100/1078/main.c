#include <stdio.h>

int main(void)
{
    int n;
    int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            result += i;
        }
    }
    printf("%d\n", result);
}
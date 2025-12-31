#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    scanf("%d", &n);
    while (0 < n)
    {
        printf("%d\n", n);
        n -= i;
    }
}
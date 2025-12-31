#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    scanf("%d", &n);
    while (0 < n)
    {
        n -= i;
        printf("%d\n", n);
    }
}
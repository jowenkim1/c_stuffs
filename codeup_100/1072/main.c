#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
reget:
    if (n <= 0)
    {
        return 0;
    }
    scanf("%d", &m);
    printf("%d\n", m);
    n -= 1;
    goto reget;
}
#include <stdio.h>

int main(void)
{
    long long x;
    long long y = 0;
    int idx = 1;

    scanf("%lld", &x);
    while (x > y)
    {
        y += idx;
        idx += 1;
    }
    printf("%lld\n", y);
}

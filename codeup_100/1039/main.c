#include <stdio.h>

int main(void)
{
    long x, y;
    scanf("%ld %ld", &x, &y);
    long long z = x + y;
    printf("%lld", z);
}
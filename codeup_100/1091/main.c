#include <stdio.h>

int main(void)
{
    int a, m, d, n;
    scanf("%d %d %d %d", &a, &m, &d, &n);
    long long result = a;
    for (int i = 0; i < n-1; i++)
    {
        result *= m;
        result += d;
    }
    printf("%lld", result);
}
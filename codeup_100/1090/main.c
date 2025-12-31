#include <stdio.h>

int main(void)
{

    int a, r, n;
    scanf("%d %d %d", &a, &r, &n);
    long long result = a;
    for (int i = 0; i < n - 1; i++)
    {
        result *= r;
    }

    printf("%lld", result);
}
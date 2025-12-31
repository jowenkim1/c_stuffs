#include <stdio.h>

int main(void)
{
    long long h, b, c, s;
    long double size;

    scanf("%lld %lld %lld %lld", &h, &b, &c, &s);

    size = (long double)h * b * c * s / (8.0L * 1024 * 1024);
    printf("%.1Lf MB", size);
}

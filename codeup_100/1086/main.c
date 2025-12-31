#include <stdio.h>

int main(void)
{
    long long w, h, b;
    long double size;

    scanf("%lld %lld %lld", &w, &h, &b);

    size = (long double)w * h * b / (8.0L * 1024 * 1024);
    printf("%.2Lf MB", size);
}

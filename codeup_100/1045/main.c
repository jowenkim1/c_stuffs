#include <stdio.h>

int main(void)
{
    unsigned int a, b;
    scanf("%d %d", &a, &b);
    printf("%u\n", a + b);
    printf("%u\n", a - b);
    printf("%u\n", a * b);
    printf("%u\n", a / b);
    printf("%u\n", a % b);
    
    printf("%.2f\n", (double)a / b);
}
#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int day = 1;
    while (
        day % a != 0 || day % b != 0 || day % c != 0)
    {
        day += 1;
    }
    printf("%d", day);
}
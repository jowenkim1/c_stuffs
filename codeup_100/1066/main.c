#include <stdio.h>

void logic(int val)
{
    if (val % 2)
    {
        printf("odd\n");
    }
    else
    {
        printf("even\n");
    }
}

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    logic(a);
    logic(b);
    logic(c);
}
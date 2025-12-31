#include <stdio.h>

int main(void)
{
    char a = 'a';
    char x;
    scanf("%c", &x);
    while (a < x + 1)
    {
        printf("%c ", a);
        a += 1;
    }
}
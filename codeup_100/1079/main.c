#include <stdio.h>

int main(void)
{
    char x = 0;
    while (x != 'q')
    {
        scanf(" %c", &x);
        printf("%c\n", x);
    }
}
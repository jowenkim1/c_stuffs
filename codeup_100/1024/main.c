#include <stdio.h>

int main(void)
{
    char data[21];
    scanf("%s", data);
    char *current = data;
    while (*current != '\0')
    {
        printf("'%c'\n", *current);
        current += 1;
    }
}
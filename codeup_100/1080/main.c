#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    int result = 0;
    scanf("%d", &n);
    while (1)
    {
        result += i;
        i += 1;
        if (n <= result)
        {
            break;
        }
    }
    printf("%d", i - 1);
}
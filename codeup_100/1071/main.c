#include <stdio.h>

int main(void)
{
    int n;
reload:
    scanf("%d", &n);
    if (n == 0)
    {
        return 0;
    }

    printf("%d\n", n);
    goto reload;
}
#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    int x = 10000;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        if (m < x)
        {
            x = m;
        }
    }
    printf("%d", x);
}
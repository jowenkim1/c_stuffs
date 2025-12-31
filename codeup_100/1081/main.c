#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            printf("%d %d\n", i, j);
        }
    }
}
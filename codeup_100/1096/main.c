#include <stdio.h>

int main(void)
{
    int n, x, y;
    int a[20][20] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        a[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

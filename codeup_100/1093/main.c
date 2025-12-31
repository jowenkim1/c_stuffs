#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    int arr[23 + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        arr[m] += 1;
    }
    for (int i = 1; i < 23 + 1; i++)
    {
        printf("%d ", arr[i]);
    }
}
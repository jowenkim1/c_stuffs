#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        arr[n-i] = m;
    }
    for (int i = 1; i < n+1; i++)
    {
        printf("%d ", arr[i]);
    }
}
#include <stdio.h>

int main(void)
{
    int h, w, n;
    scanf("%d %d", &h, &w);
    scanf("%d", &n);

    int arr[h][w];                 // VLA
    for (int i = 0; i < h; i++)     // 0 초기화
        for (int j = 0; j < w; j++)
            arr[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        int l, d, x, y;
        scanf("%d %d %d %d", &l, &d, &x, &y);

        x--; y--; // 입력이 1-based라고 가정 (대부분 이 문제는 그럼)

        if (d == 0) // 가로
        {
            for (int k = 0; k < l; k++)
                arr[x][y + k] = 1;
        }
        else // 세로
        {
            for (int k = 0; k < l; k++)
                arr[x + k][y] = 1;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

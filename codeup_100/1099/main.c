#include <stdio.h>

int main(void)
{
    int arr[10][10];
    int x = 1;
    int y = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    while (1)
    {
        // 현재 위치 표시 (먹이를 만나도 9로 바꾸고 끝내야 함)
        if (arr[y][x] == 0)
            arr[y][x] = 9;
        else if (arr[y][x] == 2)
        {
            arr[y][x] = 9;
            break;
        }

        // 오른쪽 우선
        if (arr[y][x + 1] == 0 || arr[y][x + 1] == 2)
        {
            x++;
        }
        // 아래로
        else if (arr[y + 1][x] == 0 || arr[y + 1][x] == 2)
        {
            y++;
        }
        // 둘 다 막힘
        else
        {
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

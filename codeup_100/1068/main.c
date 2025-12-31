#include <stdio.h>

int main(void)
{
    int score;
    scanf("%d", &score);
    if (90 <= score)
    {
        printf("A");
    }
    else if (70 <= score)
    {
        printf("B");
    }
    else if (40 <= score)
    {
        printf("C");
    }
    else
    {
        printf("D");
    }
}
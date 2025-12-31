#include <stdio.h>
#include <math.h>

int main(void)
{
    char data[6];
    scanf("%s", data);

    for (int i = 0; i < 5; i++)
    {
        int digit = data[i] - '0';
        int mul = 1;
        for (int k = 0; k < 4 - i; k++)
        {
            mul *= 10;
        }
        printf("[%d]\n", digit * mul);
    }
}
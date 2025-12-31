#include <stdio.h>

int main(void)
{
    int int_part;
    char float_part[7];
    scanf("%d.%s", &int_part, float_part);
    printf("%d\n", int_part);
    printf("%s\n", float_part);
}
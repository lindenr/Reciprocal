#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
    long long unsigned digits = 0, num = 1, cur;
    if (argc < 2)
    {
        printf("Usage: reciprocal [-d digits] num\nOutputs the first d digits of 1/num.\n\n");
        return 0;
    }

    if (argc != 2)
    {
        num = 3;
        digits = 2;
    }
    if (digits) digits = atoi(argv[digits]);
    else digits = 10;
    num = atoi(argv[num]);
    if ((!num) || (!digits))
    {
        printf("Fatal: invalid num or digits.\n");
        return 0;
    }
    printf("Answer: ");
    if (num == 1)
    {
        printf("1\n");
        return 0;
    }
    cur = 1;
    printf("%d.", cur/num); cur %= num;
    cur *= 10; -- digits;
    for (; digits; cur*=10, --digits)
    {
        printf("%d", cur/num);
        cur %= num;
    }
    printf("\n");
    return 0;
}

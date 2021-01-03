#include <stdio.h>
#include <stdlib.h>

long f(int n)
{
    long result;
    if (n == 0)
        return 1;
    if (n == 2)
        return 3;
    result = 4 * f(n - 2) - f(n - 4);
    return result;
}
int main()
{
    int n;
    long result;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        if (n % 2)
        {
            printf("0\n");
            continue;
        }
        result = f(n);
        printf("%ld\n", result);
    }
}

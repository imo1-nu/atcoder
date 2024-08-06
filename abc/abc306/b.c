#include <stdio.h>

int main()
{
    unsigned long long int N = 64, S = 0, a, i, j;

    for (i = 0, j = 1; i < N; i++, j = j * 2) {
        scanf("%lld", &a);
        S += a * j;
    }

    printf("%llu\n", S);
    return 0;
}
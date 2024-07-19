#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if (N % 5 < 3) printf("%d\n", N - N % 5);
    else printf("%d\n", N + 5 - N % 5);
    return 0;
}
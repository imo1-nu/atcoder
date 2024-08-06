#include <stdio.h>

int main()
{
    int N, M, P, i;
    scanf("%d %d %d", &N, &M, &P);
    for (i = 0; M + P * i <= N; i++) {}
    printf("%d\n", i);
    return 0;
}
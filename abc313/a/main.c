#include <stdio.h>

int main()
{
    int N, P[101], i, max;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &P[i]);

    for (i = 2, max = P[1]; i <= N; i++) {
        if (max <= P[i]) max = P[i] + 1;
    }

    printf("%d\n", max - P[1]);
    return 0;
}
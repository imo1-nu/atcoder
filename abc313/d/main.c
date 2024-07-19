#include <stdio.h>

int main()
{
    int N, K, i, j, T[1001];
    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i++) {
        printf("? ");
        for (j = 0; j < K - 1; j++) printf("%d ", i + j);
        printf("%d\n", i + K - 1);
        fflush(stdout);
        scanf("%d", &T[i]);
    }

    
}
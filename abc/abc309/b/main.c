#include <stdio.h>

int main()
{
    int N, i, j;
    char A[101][101];
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%s", A[i] + 1);
    }

    printf("%c", A[2][1]);
    for (i = 1; i < N; i++) printf("%c", A[1][i]);
    printf("\n");

    for (i = 2; i < N; i++) {
        printf("%c", A[i + 1][1]);
        for (j = 2; j < N; j++) printf("%c", A[i][j]);
        printf("%c\n", A[i - 1][N]);
    }

    printf("%s%c\n", A[N] + 2, A[N - 1][N]);

    return 0;
}
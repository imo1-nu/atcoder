#include <stdio.h>

int main()
{
    int N, A[101], B[101], C[101], D[101], i, j, k;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    int E[101][101] = {}, count = 0;
    for (i = 1; i <= N; i++) {
        for (j = A[i] + 1; j <= B[i]; j++) {
            for (k = C[i] + 1; k <= D[i]; k++) {
                E[j][k] = 1;
            }
        }
    }
    for (i = 1; i <= 100; i++) {
        for (j = 1; j <= 100; j++) {
            if (E[i][j] == 1) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
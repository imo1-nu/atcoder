#include <stdio.h>

void confection (int N, int D, int *C, int *X, int *Y, int i)
{
    int j;
    for (j = 0; j < N; j++) {
        if (C[j] == 0 && (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= D * D) {
            C[j] = 1;
            confection (N, D, C, X, Y, j);
        }
    }
}

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    int C[N], X[N], Y[N], i;
    for (i = 0; i < N; i++) {
        C[i] = 0;
        scanf("%d %d", &X[i], &Y[i]);
    }
    C[0] = 1;

    confection(N, D, C, X, Y, 0);
    for (i = 0; i < N; i++) {
        if (C[i] == 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
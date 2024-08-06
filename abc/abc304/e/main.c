#include <stdio.h>

int N, M, K, Q;

int ans (int *u, int *v, int *x, int *y)
{
    int i;
}

int main()
{
    scanf("%d %d", &N, &M);
    int i, j, u[M + 1], v[M + 1], E[N + 1][N + 1];
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            E[i][j] = 0;
        }
    }
    for (i = 0; i < M; i++) {
        scanf("%d %d", &u[i], &v[i]);
        E[u[i]][v[i]] = 1;
        E[v[i]][u[i]] = 1;
    }
    scanf("%d", K);
    int x[K], y[K];
    for (i = 0; i < K; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d %d", &u[M], &v[M]);
        for (i = 0; i < K; i++) {
            if (E[x[i]][y[i]] == 0) {
                if (u[M] != x[i]) {}
            }
        }
        if () printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
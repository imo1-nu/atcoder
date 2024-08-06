#include <stdio.h>

int main()
{
    int N, i, j;
    long long D[17][17] = {};
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        for (j = i + 1; j <= N; j++) {
            scanf("%d", &D[i][j]);
            D[j][i] = D[i][j];
        }
    }
}
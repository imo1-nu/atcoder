#include <stdio.h>

int main()
{
    int N, M, P[101], C[101], F[101][102] = {}, i, j, k, l, flag = 0, ans = 0;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &P[i], &C[i]);
        for (j = 1; j <= C[i]; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (i = j) continue;
            l = 1;
            for (k = 1; F[i][k] != 0; k++, l++) {
                while (F[i][k] > F[j][l] && F[j][l] != 0) l++;
                if (F[i][k] < F[j][l] || F[j][l] == 0) break;
            }
            if (F[i][k] == 0 && (k < l || P[i] > P[j])) {
                ans = 1;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    if (ans == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
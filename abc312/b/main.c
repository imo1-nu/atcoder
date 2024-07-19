#include <stdio.h>

int main()
{
    int N, M, i, j, k, l, ans, flag = 0;
    char S[103][103];
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) scanf("%s", S[i] + 1);

    for (i = 1; i <= N - 8; i++) {
        for (j = 1; j <= M - 8; j++) {
            ans = 1;

            for (k = i; k <= i + 2; k++) {
                for (l = j; l <= j + 2; l++) {
                    if (S[k][l] != '#' || S[k + 6][l + 6] != '#') {
                        ans = 0;
                        break;
                    }
                }
            }

            if (ans == 0) continue;

            for (k = i; k <= i + 2; k++) {
                if (S[k][j + 3] != '.' || S[k + 6][j + 5] != '.') {
                    ans = 0;
                    break;
                }
            }

            if (ans == 0) continue;

            for (l = j; l <= j + 3; l++) {
                if (S[i + 3][l] != '.' || S[i + 5][l + 5] != '.') {
                    ans = 0;
                    break;
                }
            }

            if (ans == 1) {
                printf("%d %d\n", i, j);
                flag = 1;
            }
        }
    }
    if (flag == 0) printf("\n");

    return 0;
}
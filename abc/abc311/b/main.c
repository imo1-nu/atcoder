#include <stdio.h>

int main()
{
    int N, D, i, j, ans = 0, flag = 0;
    char S[101][101] = {};
    scanf("%d %d", &N, &D);
    for (i = 0; i < N; i++) scanf("%s", S[i]);

    for (j = 0; j < D; j++) {
        for (i = 0; i < N; i++) {
            if (S[i][j] == 'x') {
                flag = 0;
                break;
            }
        }
        if (i == N) flag++;
        if (flag > ans) ans = flag;
    }
    printf("%d\n", ans);
    return 0;
}
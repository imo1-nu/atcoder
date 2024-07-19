#include <stdio.h>

int main()
{
    int N, M, A[100000], B[100000], i, C[51] = {}, count = 0, ans;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= M; i++) scanf("%d %d", &A[i], &B[i]);

    for (i = 1; i <= M; i++) C[B[i]] = -1;

    for (i = 1; i <= N; i++) {
        if (C[i] == 0) {
            ans = i;
            count++;
        }
    }

    if (count == 1) printf("%d\n", ans);
    else printf("-1\n");

    return 0;
}
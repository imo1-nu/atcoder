#include <stdio.h>

int main()
{
    int N, A[100001], i, j, s;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        s = 0;
        for (j = 1; j <= 7; j++) {
            scanf("%d", &A[j]);
            s += A[j];
        }
        if (i < N) printf("%d ", s);
    }
    printf("%d\n", s);
    return 0;
}
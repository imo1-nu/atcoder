#include <stdio.h>

int main()
{
    int N, X, A[101], i;
    scanf("%d %d", &N, &X);
    for (i = 0; i < N - 1; i++) scanf("%d", &A[i]);
    int min = 100, max = 0, sum = 0;
    for (i = 0; i < N - 1; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
        sum += A[i];
    }
    if (sum - max >= X) printf("0\n");
    else if (sum - min >= X) printf("%d\n", X - sum + max + min);
    else printf("-1\n");
    return 0;
}
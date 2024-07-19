#include <stdio.h>

int main()
{
    long long N, A[200001], i, sum = 0, ave, a, count = 0, count2 = 0;
    scanf("%lld", &N);
    for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
    for (i = 1; i <= N; i++) sum += A[i];
    ave = sum / N;
    a = sum % ave;

    for (i = 1; i <= N; i++) {
        if (A[i] < ave) {
            count += ave - A[i];
            A[i] = ave;
        }
    }

    for (i = 1; i <= N; i++) {
        if (A[i] == ave) count2++;
    }

    if (count2 > N - a) count += count2 - N + a;

    printf("%lld\n", count);

    return 0;
}
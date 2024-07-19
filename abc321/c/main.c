#include <stdio.h>

int main()
{
    long long K;
    scanf("%lld", &K);
    int i, j, k, C[11], S[11];
    C[1] = 10;
    for (i = 2; i <= 10; i++) {
        C[i] = C[i - 1] * (11 - i) / i;
        printf("%d\n", C[i]);
    }
    C[1] = 9;
    S[0] = 0;
    for (i = 1; i <= 10; i++) {
        S[i] = S[i - 1] + C[i];
    }

    for (i = 1; i <= 10; i++) {
        if (S[i] >= K) break;
    }
    int A[i];
    for (j = 0; j < i; j++) A[j] = j;

    for (j = 1; j < K - S[i - 1]; j++) {
        
    }
    return 0;
}
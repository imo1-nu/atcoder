#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    char S[N][100];
    long long A[N], i, min[2];
    min[0] = 1000000000;
    min[1] = 0;
    for (i = 0; i < N; i++) {
        scanf("%s %lld", S[i], &A[i]);
        if (min[0] > A[i]) {
            min[0] = A[i];
            min[1] = i;
        }
    }

    for (i = 0; i < N; i++) {
        printf("%s\n", S[(min[1] + i) % N]);
    }

    return 0;
    
}
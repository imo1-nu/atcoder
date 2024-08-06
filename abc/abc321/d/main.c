#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2)
{
	if (*(long long *)n1 > *(long long *)n2)
	{
		return 1;
	}
	else if (*(long long *)n1 < *(long long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
    long long N, M, A[200000], B[200000], P, i, j, sum = 0;
    scanf("%lld %lld %lld", &N, &M, &P);
    for (i = 0; i < N; i++) scanf("%lld", &A[i]);
    for (i = 0; i < M; i++) scanf("%lld", &B[i]);
    qsort(A, N, sizeof(long long), cmpnum);
    qsort(B, M, sizeof(long long), cmpnum);

    long long S[200000];
    S[0] = B[0];
    for (i = 1; i < M; i++) S[i] = S[i - 1] + B[i];

    long long l = 0, r = M, mid;
    for (i = 0; i < N; i++) {
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (A[i] + B[mid] > P) r = mid;
            else l = mid;
        }
        sum += A[i] * (l + 1) + S[l];
        sum += P * (M - l - 1);
    }

    printf("%lld\n", sum);
    return 0;
}
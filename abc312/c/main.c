#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2)
{
	if (*(long *)n1 > *(long *)n2)
	{
		return 1;
	}
	else if (*(long *)n1 < *(long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int nibun1(int* A, int num, int ans)
{
    int a, b, mid;
    for (a = 0, b = num; a + 1 < b;) {
        mid = (a + b) / 2;
        if (A[mid] > ans) b = mid;
        else a = mid;
    }
    return a;
}

int nibun2(int* A, int num, int ans)
{
    int a, b, mid;
    for (a = 0, b = num; a + 1 < b;) {
        mid = (a + b) / 2;
        if (A[mid] >= ans) b = mid;
        else a = mid;
    }
    return a;
}

int main()
{
    int N, M, i, l, r, mid;
    scanf("%d %d", &N, &M);
    int A[N], B[M], C[N + M];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        C[i] = A[i];
    }
    for (i = 0; i < M; i++) {
        scanf("%d", &B[i]);
        C[N + i] = B[i];
    }
    qsort(A, N, sizeof(int), cmpnum);
    qsort(B, M, sizeof(int), cmpnum);
    qsort(C, N + M, sizeof(int), cmpnum);

    for (l = 0, r = N + M; l + 1 < r;) {
        mid = (l + r) / 2;
        if (nibun1(A, N, C[mid]) + 1 < M - nibun2(B, M, C[mid]) - 1) r = mid;
        else l = mid;
    }

    printf("%d\n", C[l]);
    printf("%d\n", A[nibun1(A, N, 120)]);
    return 0;
}
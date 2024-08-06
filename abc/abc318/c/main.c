#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2)
{
	if (*(int *)n1 > *(int *)n2)
	{
		return -1;
	}
	else if (*(int *)n1 < *(int *)n2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
    int N, i, j;
    long long sum, G[200001] = {}, D, P, F[200001];

    scanf("%d %lld %lld", &N, &D, &P);
    for (i = 1; i <= N; i++) scanf("%lld", &F[i]);

    qsort(F + 1, N, sizeof(long long), cmpnum);

    for (i = 1; i <= N; i++) G[i] = F[i] + G[i - 1];

    for (i = 0; i <= N; i += D) {
        if (G[i + D] - G[i] < P) break;
    }

    if (G[N] - G[(N / D) * D] > P) {
        sum = ((N / D + 1) * P);
    }
    else {
        sum = (i / D) * P;
        for (j = i + 1; j <= N; j++) sum += F[j];
    }

    printf("%lld\n", sum);
    return 0;
}
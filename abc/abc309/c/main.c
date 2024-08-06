#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} data;

int cmpnum(const void * n1, const void * n2)
{
	if (((data *)n1)->a < ((data *)n2)->a)
	{
		return 1;
	}
	else if (((data *)n1)->a > ((data *)n2)->a)
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
    int N, K, i, sum = 0;
    data D[300000];
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) scanf("%d %d", &(D[i].a), &(D[i].b));

    qsort(D, N, sizeof(data), cmpnum);

    for (i = 0; i < N; i++) {
        sum += D[i].b;
        if (sum > K) break;
    }

    printf("%d\n", D[i].a + 1);
    return 0;

}
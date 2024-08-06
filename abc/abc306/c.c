#include <stdio.h>
#include <stdlib.h>

struct func{
  int x;
  int f;
};

int cmpnum(const void * n1, const void * n2)
{
	if (((struct func *)n1)->f > ((struct func *)n2)->f)
	{
		return 1;
	}
	else if (((struct func *)n1)->f < ((struct func *)n2)->f)
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
    int N;
    scanf("%d", &N);
    int A[3 * N], i;
    struct func B[N + 1];

    for (i = 0; i < N + 1; i++) {
        B[i].x = 0;
        B[i].f = 0;
    }

    for (i = 0; i < 3 * N; i++) {
        scanf("%d", &A[i]);
        if (B[A[i]].x == 0) {
            B[A[i]].x++;
            continue;
        }
        if (B[A[i]].x == 1) {
            B[A[i]].x++;
            B[A[i]].f = i + 1;
        }
    }

    for (i = 0; i < N + 1; i++) {
        B[i].x = i;
    }

    qsort(B, N + 1, sizeof(struct func), cmpnum);

    for (i = 1; i < N; i++) {
        printf("%d ", B[i].x);
    }

    printf("%d\n", B[N].x);

    return 0;
}
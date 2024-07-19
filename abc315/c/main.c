#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int F;
    int S;
} CUP;

int cmpnum(const void * n1, const void * n2)
{
	if (((CUP *)n1)->S > ((CUP *)n2)->S)
	{
		return 1;
	}
	else if (((CUP *)n1)->S > ((CUP *)n2)->S)
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
    int N, i;
    CUP cup[300000];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d", &(cup[i].F), &(cup[i].S));
    }

    qsort(cup, N, sizeof(CUP), cmpnum);

    if (cup[N - 1].F != cup[N - 2].F) printf("%d\n", cup[N - 1].S + cup[N - 2].S);
    else {
        for (i = N - 3; i >= 0; i--) {
            if (cup[N - 1].F != cup[i].F) break;
        }

        if (N == 2) printf("%d\n", cup[N - 1].S + cup[N - 2].S / 2);
        else if (cup[N - 2].S / 2 > cup[i].S) printf("%d\n", cup[N - 1].S + cup[N - 2].S / 2);
        else printf("%d\n", cup[N - 1].S + cup[i].S);
    }
    return 0;
}
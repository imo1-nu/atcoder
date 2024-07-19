#include <stdio.h>

int main()
{
    int N, A[200001], B[200001] = {}, i, j, num = 1;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    A[0] = 1;
    for (i = 0; B[i] < 2; B[i]++) i = A[i];

    for (j = A[i]; j != i; j = A[j]) num++;
    printf("%d\n", num);
    for (j = A[i]; j != i; j = A[j]) printf("%d ", j);
    printf("%d\n", i);
    return 0;
}
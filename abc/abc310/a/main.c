#include <stdio.h>

int main()
{
    int N, P, Q, D[100001], i, min;
    scanf("%d %d %d", &N, &P, &Q);
    for (i = 1; i <= N; i++) scanf("%d", &D[i]);
    for (i = 2, min = D[1]; i <= N; i++) if (min > D[i]) min = D[i];
    if (P < Q + min) printf("%d\n", P);
    else printf("%d\n", Q + min);
    return 0;
}
#include <stdio.h>

int main()
{
    int N1, N2, M, node[300001][300001] = {}, passed[300001] = {}, max, a, b, i, j;
    scanf("%d %d %d", &N1, &N2, &M);
    for (i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);
        node[a][b] = 1;
        node[b][a] = 1;
    }

    for () {}
}
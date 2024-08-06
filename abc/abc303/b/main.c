#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[m][n];
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int adj[51][51] = {}, ans = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - 1; j++) {
            adj[a[i][j]][a[i][j + 1]]++;
            adj[a[i][j + 1]][a[i][j]]++;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++){
            if (adj[i][j] == 0) ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
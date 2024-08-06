#include <stdio.h>

int rotate1 (int a, int b, int c, int n) {
    int i, d;
    for(i = 0; i < c; i++){
        d = a;
        a = n - 1 - b;
        b = d;
    }
    return a;
}

int rotate2 (int a, int b, int c, int n) {
    int i, d;
    for(i = 0; i < c; i++){
        d = a;
        a = n - 1 - b;
        b = d;
    }
    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n], b[n][n];

    int i, j, r;
    for (i = 0; i < n * n; i++) {
        scanf("%d", &a[i / n][i % n]);
    }
    for (i = 0; i < n * n; i++) {
        scanf("%d", &b[i / n][i % n]);
    }

    for (j = 0; j < 4; j++) {
        for (i = 0; i < n * n; i++) {
            if (a[rotate1(i / n, i % n, j, n)][rotate2(i / n, i % n, j, n)] == 1) {
                if (b[i / n][i % n] == 0) {
                    break;
                }
            }
        }
        if (i == n * n) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;

}
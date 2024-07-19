#include <stdio.h>

int ichigo (int l, int r, int d, int u, int *p, int *q, int N)
{
    int i, c;
    for (i = 0, c = 0; i < N; i++) {
        if (p[i] > l && p[i] < r && q[i] > d && q[i] < u) c++;
    }
    return c;
}

int main()
{
    int W, H, N, A, B;
    scanf("%d %d", &W, &H);
    scanf("%d", &N);
    int p[N], q[N], i, j;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &p[i], &q[i]);
    }
    scanf("%d", &A);
    int a[A + 2];
    a[0] = 0;
    for (i = 1; i <= A; i++) {
        scanf("%d", &a[i]);
    }
    a[A + 1] = W;
    scanf("%d", &B);
    int b[B + 2];
    b[0] = 0;
    for (i = 1; i <= B; i++) {
        scanf("%d", &b[i]);
    }
    b[B + 1] = H;

    int min = N, max = 0, c;
    for (i = 0; i <= B; i++) {
        for (j = 0; j <= A; j++) {
            c = ichigo (a[j], a[j + 1], b[i], b[i + 1], p, q, N);
            if (c > max) max = c;
            else if (c < min) min = c;
        }
    }

    printf("%d %d\n", min, max);
    return 0;
}
#include <stdio.h>

void move(char c, int *X, int *Y)
{
    if (c == 'R') *X = *X + 1;
    if (c == 'L') *X = *X - 1;
    if (c == 'U') *Y = *Y + 1;
    if (c == 'D') *Y = *Y - 1;
}

int item(int *x, int *y, int X, int Y, int M, int K, int H)
{
    int i;
    for (i = 0; i < M; i++) {
        if (X == x[i] && Y == y[i] && H - 1 < K) return K;
    }
    return H - 1;
}

int main()
{
    int N, M, H, K;
    scanf("%d %d %d %d", &N, &M, &H, &K);
    char S[N];
    scanf("%s", S);
    int i, x[M], y[M];
    for (i = 0; i < M; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int X = 0, Y = 0, ans = 1;
    for (i = 0; i < N - 1; i++) {
        move(S[i], &X, &Y);
        if (H = item(x, y, X, Y, M, K, H) == 0) {
            ans = 0;
            break;
        }
    }

    if (ans == 1) printf("Yes\n");
    else printf("No\n");
}
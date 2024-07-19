#include <stdio.h>

int func1(char* A, int *H, int W)
{
    int i;
    for (i = 1; i <= W; i++) {
        if (A[i] == '#') return 0;
    }
    *H -= 1;
    return 0;
}

int func2(char** p, int H, int *W)
{
    int i;
    for (i = 1; i <= H; i++) {
        if (p[i][1] == '#') return 0;
    }
    *W -= 1;
    return 0;
}

int main()
{
    int H[3], W[3], i, j;
    char A[11][11], B[11][11], X[11][11];
    scanf("%d", &H[0], &W[0]);
    for (i = 1; i <= H[0]; i++) {
        scanf("%s", A[i]);
    }

    scanf("%d", &H[1], &W[1]);
    for (i = 1; i <= H[1]; i++) {
        scanf("%s", B[i]);
    }

    scanf("%d", &H[2], &W[2]);
    for (i = 1; i <= H[2]; i++) {
        scanf("%s", X[i]);
    }

    char *p[11];
    for (i = 1; i <= H[0]; i++) {
        p[i] = A[i];
    }


}
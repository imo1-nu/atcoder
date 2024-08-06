#include <stdio.h>

int main()
{
    int c[4][4], i, j, count = 0, x = 1;
    float ans = 1;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    for (i = 1; i <= 9; i++) x *= i;

    for (i = 1; i <= 3; i++) {
        if (c[i][1] == c[i][2] || c[i][1] == c[i][3] || c[i][2] == c[i][3]) count++;
    }

    for (j = 1; j <= 3; j++) {
        if (c[1][j] == c[2][j] || c[1][j] == c[3][j] || c[2][j] == c[3][j]) count++;
    }

    if (c[1][1] == c[2][2] || c[1][1] == c[3][3] || c[2][2] == c[3][3]) count++;
    if (c[1][3] == c[2][2] || c[1][3] == c[3][1] || c[2][2] == c[3][1]) count++;

    for (i = 0; i < count; i++) {
        ans *= 2;
        ans /= 3;
    }

    printf("%.32f\n", ans);
    return 0;
}
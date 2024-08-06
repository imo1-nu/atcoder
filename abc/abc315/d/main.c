#include <stdio.h>

int main()
{
    int H, W, i, j, h, w;
    char c[2001][2001] = {};
    char **p = c;
    scanf("%d %d", &H, &W);
    for (i = 1; i <= H; i++) scanf("%s", c[i] + 1);
    while (1) {
        if (w >= 2) {
            for (i = 1; i <= h; i++) {
                for (j = 1; j <= w; j++) {
                    if (c[i][j] != c[i][1]) break; 
                }
                if (j == w + 1) {
                    p = c
                }
            }
        }
    }
}
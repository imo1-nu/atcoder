#include <stdio.h>

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    char S[H][W];
    int i, j;
    for (i = 0; i < H; i++) {
        scanf("%s", S[i]);
    }

    int c, k = 0;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            c = 0;
            if (S[i][j] == '.') {
                if (i > 0) {
                    if (S[i - 1][j] == '#') c++;
                }
                if (i < H - 1) {
                    if (S[i + 1][j] == '#') c++;
                }
                if (j > 0) {
                    if (S[i][j - 1] == '#') c++;
                }
                if (j < W - 1) {
                    if (S[i][j + 1] == '#') c++;
                }

                if (c >= 2) {
                    printf("%d %d\n", i + 1, j + 1);
                    k = 1;
                }
            }
            if (k == 1) break;
        }
        if (k == 1) break;
    }
    
    return 0;
}
#include <stdio.h>

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    char s[h][w];
    int i;
    for (i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }

    int j, k, l, key = 0;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (s[i][j] == 's') {
                for (k = -1; k < 2; k++) {
                    for (l = -1; l < 2; l++) {
                        if (i + 4*k >= 0 && i + 4*k < h && j + 4*l >= 0 && j + 4*l < w) {
                            if (s[i + k][j + l] == 'n' && s[i + 2*k][j + 2*l] == 'u' && s[i + 3*k][j + 3*l] == 'k' && s[i + 4*k][j + 4*l] == 'e') {
                                key = 1;
                                break;
                            }
                        }
                    }
                    if (key == 1) break;
                }
            }
            if (key == 1) break;
        }
        if (key == 1) break;
    }

    for (key = 0; key < 5; key++) {
        printf("%d %d\n", i + key*k + 1, j + key*l + 1);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    char a[h][w], b[h][w];
    int i;
    for (i = 0; i < h; i++) {
        scanf("%s", a[i]);
    }
    for (i = 0; i < h ; i++) {
        scanf("%s", b[i]);
    }

    int s, t;
    for (s = 0; s < h; s++) {
        for (t = 0; t < w; t++) {
            for (i = 0; i < h * w; i++) {
                if (a[(i / w + s) % h][(i + t) % w] != b[i / w][i % w]) {
                    break;
                }
            }
            if (i == h * w) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

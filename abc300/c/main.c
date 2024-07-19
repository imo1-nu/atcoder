#include <stdio.h>

int min(int a, int b)
{
    if (a < b) return a;
    else       return b;
}

int check(int i, int j, int h, int w, char c[][])
{
    int k = 0;
    while (i + k < h && i - k >= 0 && j + k < w && j - k >= 0) {
        if (c[i + k][j + k] == '#' && c[i + k][j - k] == '#' && c[i - k][j + k] == '#' && c[i - k][j - k] == '#') k++;
        else break;
    }

    return k;
}

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);

    char c[h][w];
    int i, j;
    for (i = 0; i < h; i++) {
        scanf("%s", c[i]);
    }

    int n = min(h,w);
    int s[n], m;
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            m = check(i, j, h, w, c);
            s[m]++;
        }
    }

    for (i = 1; i < n; i++) {
        if (i < n -1) printf("%d ", s[i]);
        else printf("%d\n", s[i]);
    }

    return 0;
}
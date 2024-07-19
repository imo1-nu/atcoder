#include <stdio.h>

int ans(int l, int r)
{
    int i, s;
    for (i = 0; i < 20; i++) {
        printf("? %d\n", (l + r) / 2);
        fflush(stdout);
        scanf("%d", &s);
        if (s == 0) l = (l + r) / 2;
        else        r = (l + r) / 2;
    }
    return l;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("! %d\n", ans(0, n));
    return 0;
}
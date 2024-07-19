#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int c[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        if (a + b == c[i]) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}
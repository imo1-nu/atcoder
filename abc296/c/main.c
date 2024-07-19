#include <stdio.h>
#include <stdlib.h>

int c (const int *a, const int *b)
{
    return *a - *b;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int i, j, a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), c);

    for (i = 0, j = 0; i < n && j < n;) {
        c = a[i] - a[j];
        if (c == x) {
            printf("Yes\n");
            return 0;
        }
        else {
            if (c < x) i++;
            else j++;
        }
    }

    printf("No\n");
    return 0;
}
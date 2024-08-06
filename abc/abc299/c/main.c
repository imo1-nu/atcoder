#include <stdio.h>

int hantei(int *n, char *s, int start, int max)
{
    int i;
    for (i = start; i < *n; i++) {
        if (s[i] == '-') {
            if (i - start > max) max = i - start;
            return hantei(n, s, i + 1, max);
        }
    }

    if (start != 0 && i - start > max) max = i - start;

    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);

    int a = hantei(&n, s, 0, 0);
    if (a == 0) printf("%d\n", -1);
    else printf("%d\n", a);
    return 0;
}
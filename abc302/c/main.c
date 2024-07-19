#include <stdio.h>

int incorrect_num(char *s1, char *s2, int m)
{
    int i, num;
    for (i = 0, num= 0; i < m; i++) {
        if (s1[i] != s2[i]) num++;
    }
    return num;
}

void reset(int *checked, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        checked[i] = 0;
    }
}

int check(int *checked, int n) 
{
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char s[n][m];
    int i, j, k;
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int checked[n];
    for (i = 0; i < n; i++) {
        checked[i] = 0;
    }

    char *p;
    for (i = 0; i < n; i++) {
        p = s[i];
        checked[i] = 1;
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (incorrect_num(p, s[k], m) == 1 && checked[k] == 0) {
                    p = s[k];
                    checked[k] = 1;
                    break;
                }
            }
        }
        if (check(checked, n) == 1) break;
        else reset(checked, n);
    }

    if (check(checked, n) == 1) printf("Yes\n");
    else printf("No\n");

    return 0;
}
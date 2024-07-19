#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);

    int i, j;
    for (i = 0, j = 0; i < n; i++) {
        if (s[i] == 'x') {
            printf("No\n");
            return 0;
        }
        else if (s[i] == 'o') j++;
    }

    if (j > 0) printf("Yes\n");
    else printf("No\n");
    return 0;
}
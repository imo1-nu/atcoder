#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int i, j;
    for (i = 0; s[i] != '|'; i++) {
    }

    for (j = i + 1; s[j] != '|'; j++) {
        if (s[j] == '*') {
            printf("in\n");
            return 0;
        }
    }

    printf("out\n");
    return 0;
}
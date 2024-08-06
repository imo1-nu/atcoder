#include <stdio.h>

int main()
{
    int n;
    char s[100];
    scanf("%d", &n);
    scanf("%s", s);
    int i, win;
    for (i = 0, win = 0; i < n; i++) {
        if (s[i] == 'T') win++;
    }

    if (win > n / 2) printf("T\n");
    else {
        if (win < (n + 1) / 2) printf("A\n");
        else {
            if (s[n - 1] == 'A') printf("T\n");
            else printf("A\n");
        }
    }

    return 0;

}
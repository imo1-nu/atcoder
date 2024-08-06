#include <stdio.h>

int main()
{
    int S[8], i, ans = 1;
    for (i = 0; i < 8; i++) {
        scanf("%d", &S[i]);
        if (S[i] % 25 != 0) ans = 0;
    }

    for (i = 0; i < 7; i++) {
        if (S[i] > S[i + 1]) ans = 0;
    }

    if (S[0] < 100 || S[7] > 675) ans = 0;

    if (ans == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
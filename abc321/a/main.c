#include <stdio.h>

int main()
{
    char N[7], i, ans = 1;
    scanf("%s", N);
    for (i = 0; N[i + 1] != '\0'; i++) {
        if (N[i] <= N[i + 1]) {
            ans = 0;
            break;
        }
    }
    if (ans) printf("Yes\n");
    else printf("No\n");
    return 0;
}
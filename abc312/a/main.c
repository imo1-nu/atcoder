#include <stdio.h>

int main()
{
    char S[3];
    scanf("%s", S);
    if (S[0] >= 'A' && S[0] <= 'G' && S[1] == (S[0] + 2 - 'A') % ('G' - 'A' + 1) + 'A' && S[2] == (S[0] + 4 - 'A') % ('G' - 'A' + 1) + 'A') printf("Yes\n");
    else printf("No\n");
    return 0;
}
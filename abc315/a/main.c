#include <stdio.h>

int main()
{
    char S[101];
    scanf("%s", S);
    int i;
    for (i = 0; S[i] != '\0'; i++) {
        if (S[i] != 'a' && S[i] != 'i' && S[i] != 'u' && S[i] != 'e' && S[i] != 'o') printf("%c", S[i]);
    }
    printf("\n");
    return 0;
}
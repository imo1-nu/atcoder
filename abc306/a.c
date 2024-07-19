#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    char S[N];
    scanf("%s", S);

    int i;
    for (i = 0; i < N; i++) {
        printf("%c%c", S[i], S[i]);
    }
    return 0;
}
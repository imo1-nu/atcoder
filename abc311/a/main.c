#include <stdio.h>

int main()
{
    int N, A = 0, B = 0, C = 0, i;
    char S[101];
    scanf("%d", &N);
    scanf("%s", S);
    for (i = 0; i < N; i++) {
        if (S[i] == 'A') A = 1;
        else if (S[i] == 'B') B = 1;
        else if (S[i] == 'C') C = 1;

        if (A == 1 && B == 1 && C == 1) break;
    }
    printf("%d\n", i + 1);
    return 0;
}
#include <stdio.h>

int main()
{
    int N, i, j, k;
    char S[200001];
    scanf("%d", &N);
    scanf("%s", S);

    for (i = 0; i < N; i++) {
        if (S[i] == '(' && i != N - 1) {
            for (j = i + 1; j < N; j++) {
                if (S[j] == '(') break;
                if (S[j] == ')') {
                    for (k = 0; j + k + 1 <= N; k++) {
                        S[i + k] = S[j + k + 1];
                    }
                    N -= j - i + 1;
                    i = 0;
                    break;
                }
            }
        }
    }

    printf("%s\n", S);
    return 0;
}
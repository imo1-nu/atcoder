#include <stdio.h>

int strlen(char *s)
{
    int i = 0;
    while(s[i]) {
        i++;
    }
    return i;
}

int main()
{
    int N, i, j, k, l, m;
    char S[101][51], A[101];

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%s", S[i]);
    }

    for (i = 1; i <= N; i++) {
        for (k = 0; k < strlen(S[i]); k++) {
            A[k] = S[i][k];
        }
        for (j = 1; j <= N; j++) {
            if (i != j) {
                for (l = 0; l < strlen(S[j]); l++) {
                    A[k + l] = S[j][l];
                }

                for (m = 0; m < (k + l) / 2; m++) {
                    if (A[m] != A[k + l - 1 - m]) break;
                }

                if (m == (k + l) / 2) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }

    printf("No\n");
    return 0;
}
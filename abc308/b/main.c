#include <stdio.h>

int strcmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) return 0;
        str1++;
        str2++;
    }
    if (*str1 == *str2) return 1;
    else return 0;
}

int main()
{
    int N, M, P[101], i, j, sum = 0;
    char C[101][21], D[101][21];
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%s", C[i]);
    }
    for (i = 1; i <= M; i++) {
        scanf("%s", D[i]);
    }
    for (i = 0; i <= M; i++) {
        scanf("%d", &P[i]);
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (strcmp(C[i], D[j])) {
                sum += P[j];
                break;
            }
        }
        if (j == M + 1) sum += P[0];
    }

    printf ("%d\n", sum);
    return 0;
}
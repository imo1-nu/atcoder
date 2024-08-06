#include <stdio.h>

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for (i = 0; i <= N; i++) {
        for (j = 1; j < 10; j++) {
            if (i * j % N == 0) {
                printf("%d", j);
                break;
            }
        }
        if (j == 10) printf("-");
    }
    printf("\n");
    return 0;
}
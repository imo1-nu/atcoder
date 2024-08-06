#include <stdio.h>

int main()
{
    int M, D[101], i, sum = 1, m, d, sum2;
    scanf("%d", &M);
    for (i = 1; i <= M; i++) {
        scanf("%d", &D[i]);
        sum += D[i];
    }
    sum = sum / 2;
    for (i = 1; i <= M; i++) {
        sum2 += D[i];
        if (sum <= sum2) {
            m = i;
            d = sum - sum2 + D[i];
            break;
        }
    }
    printf("%d %d\n", m, d);
    return 0;
}
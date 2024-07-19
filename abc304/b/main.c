#include <stdio.h>

int keta (int N)
{
    int i = 0, j, ans = 1;
    while (N / 10 != 0) {
        N = N / 10;
        i++;
    }

    for (j = 0; j < i; j++) {
        ans = ans * 10;
    }
    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);
    if (N < 1000) printf("%d\n", N);
    else printf("%d\n", N - (N % (keta(N) / 100)));
    return 0;
}
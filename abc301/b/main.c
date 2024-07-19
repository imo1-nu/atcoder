#include <stdio.h>

void print_gap (int a, int b)
{
    int i;
    if (a > b) {
        for (i = 0; a - i > b; i++) {
            printf("%d ", a - i);
        }
    }
    else {
        for (i = 0; a + i < b; i++) {
            printf("%d ", a + i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n], i, j;
    for (i = 0; i < n; i++) {
        scanf("%d ", &A[i]);
    }

    for (i = 0, j = 0; i < n - 1; i++) {
        print_gap(A[i], A[i + 1]);
    }
    printf("%d\n", A[n - 1]);

    return 0;
}
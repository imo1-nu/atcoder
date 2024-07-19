#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    if (A % 3 != 0 && A + 1 == B) printf("Yes\n");
    else printf("No\n");
    return 0;
}
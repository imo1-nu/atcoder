#include <stdio.h>

int main()
{
    long long a, b, ans;
    scanf("%lld %lld", &a, &b);
    if (a % b == 0) ans = a / b;
    else ans = (a / b) + 1;
    printf("%lld\n", ans);
    return 0;
}
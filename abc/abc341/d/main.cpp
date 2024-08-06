#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M, K;
    cin >> N >> M >> K;
    long long ans;
    for (long long i = 1, j = 1, cnt = 0; cnt < K;) {
        if (N * i < M * j) {
            ans = N * i;
            i++;
            cnt++;
        }
        else if (N * i > M * j) {
            ans = M * j;
            j++;
            cnt++;
        }
        else {
            i++;
            j++;
        }
    }
    cout << ans << endl;
}

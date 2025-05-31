#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    if (K == 0) {
        ans = (ll)N * N;
        cout << ans << endl;
        return 0;
    }
    for (int b = K + 1; b <= N; b++) {
        ll cnt = N / b * (b - K);
        cnt += max(0, N - (N / b) * b - K + 1);
        ans += cnt;
    }
    cout << ans << endl;
}

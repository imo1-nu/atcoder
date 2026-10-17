#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, W;
    cin >> N >> W;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        ll cnt = 0, w = 0;
        for (int j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                cnt += A[j];
                w += B[j];
            }
        }
        if (w <= W) ans = max(ans, cnt);
    }
    cout << ans << endl;
}

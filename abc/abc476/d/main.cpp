#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    ll X, Y;
    cin >> N >> M >> K >> X >> Y;
    vector<int> A(N), B(M);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> S(N + 1);
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i - 1];

    int ans = upper_bound(S.begin(), S.end(), X + Y * K) - S.begin() - 1;
    for (int i = 0; i < M; i++) {
        int add_k = (B[i] - 1) / K + 1;
        X += (ll)K * add_k - B[i];
        Y -= add_k;
        if (Y < 0) break;
        int j = upper_bound(S.begin(), S.end(), X + Y * K) - S.begin();
        ans = max(ans, i + j);
    }
    cout << ans << endl;
}

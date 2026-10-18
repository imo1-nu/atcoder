#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    ll sum = 0;
    for (auto a : A) sum += a;
    ll X = sum / M;

    vector<ll> W(1 << N), dp(1 << N);
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) continue;
            ll t = i | (1 << j);
            W[t] = (W[i] + A[j]) % X;
            dp[t] = max(dp[t], dp[i] + (W[t] == 0 ? 1 : 0));
        }
    }
    cout << M - dp[(1 << N) - 1] << endl;
}

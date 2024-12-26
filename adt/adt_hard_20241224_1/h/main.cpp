#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<pair<int, int>> P;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[i] == A[j] || B[i] == B[j]) {
                P.emplace_back(i, j);
            }
        }
    }

    vector<bool> dp(1 << N);
    for (int i = 0; i < (1 << N); ++i) {
        if (dp[i]) continue;
        for (auto [a, b] : P) {
            if ((i >> a & 1) || (i >> b & 1)) continue;
            dp[i | (1 << a) | (1 << b)] = true;
        }
    }

    if (dp[(1 << N) - 1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}

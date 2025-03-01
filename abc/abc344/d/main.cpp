#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string T;
    int N;
    cin >> T >> N;
    vector<int> A(N);
    vector<vector<string>> S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i].resize(A[i]);
        for (int j = 0; j < A[i]; j++) {
            cin >> S[i][j];
        }
    }
    vector<int> dp(T.size() + 1, N + 1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        auto ndp = dp;
        for (int j = 0; j < T.size(); j++) {
            for (auto &s : S[i]) {
                if (j + s.size() <= T.size() && T.substr(j, s.size()) == s) {
                    ndp[j + s.size()] = min(ndp[j + s.size()], dp[j] + 1);
                }
            }
        }
        dp = ndp;
    }
    if (dp[T.size()] > N) dp[T.size()] = -1;
    cout << dp[T.size()] << '\n';
}

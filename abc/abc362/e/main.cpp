#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<map<int, mint>>> dp(N + 1, vector<map<int, mint>>(N + 1));
    for (int i = 1; i <= N; i++) {
        dp[i][1][0]++;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][2][A[i - 1] - A[j - 1]]++;
        }
    }
    
    for (int i = 3; i <= N; i++) {
        for (int k = 3; k <= i; k++) {
            for (int j = 1; j < i; j++) {
                dp[i][k][A[i - 1] - A[j - 1]] += dp[j][k - 1][A[i - 1] - A[j - 1]];
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        mint ans = 0;
        for (int i = 1; i <= N; i++) {
            for (auto p : dp[i][k]) {
                ans += p.second;
            }
        }
        cout << ans.val() << ' ';
    }
    cout << endl;
}

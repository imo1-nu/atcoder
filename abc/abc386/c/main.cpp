#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 1e9

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int K;
    string S, T;
    cin >> K >> S >> T;

    int N = S.length();
    int M = T.length();
    int diff = M - N;

    if (K < abs(diff)) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> dp(N + 1, vector<int>(2 * K + 3, INF));
    for (int j = K + 1; j <= 2 * K + 1; j++) {
        dp[0][j] = j - K - 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2 * K + 1; j++) {
            dp[i][j] = min({dp[i - 1][j + 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            int k = i + j - (K + 1);
            if (1 <= k && k <= M && S[i - 1] == T[k - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }

    int ans = dp[N][diff + K + 1];
    if (ans <= K) cout << "Yes" << endl;
    else cout << "No" << endl;
}

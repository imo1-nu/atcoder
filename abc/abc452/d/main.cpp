#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;

    vector<vector<int>> dp(S.length(), vector<int>(T.length() + 1, -1));
    for (int i = 0; i < S.length(); i++) dp[i][0] = i;
    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < T.length(); j++) if (i > 0) dp[i][j + 1] = dp[i - 1][j + 1];
        for (int j = T.length() - 1; j >= 0; j--) if (S[i] == T[j]) dp[i][j + 1] = dp[i][j];
    }

    ll ans = 0;
    for (int i = 0; i < S.length(); i++) {
        ans += i - dp[i][T.length()];
    }
    cout << ans << endl;
}

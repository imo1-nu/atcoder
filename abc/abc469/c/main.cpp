#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    vector<pair<int, int>> dp(N + 1);
    for (int i = 0; i < N; i++) {
        if (dp[i].second > 0) dp[i + 1] = {dp[i].first, dp[i].second - 1};
        else dp[i + 1] = {dp[i].first + 1, 0};
        if (S[i] == 'o') dp[i + 1].second++;
    }
    // for (int i = 0; i <= N; i++) {
    //     cout << i << ": " << dp[i].first << ", " << dp[i].second << endl;
    // }

    vector<int> ans(N + 1);
    for (int i = 1; i <= N; i++) {
        ans[dp[i].first] = i;
    }
    for (int i = 1; i <= N; i++) {
        if (ans[i] < ans[i - 1]) ans[i] = ans[i - 1];
        cout << ans[i] << endl;
    }
}

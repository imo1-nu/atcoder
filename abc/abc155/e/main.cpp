#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.size();
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = S[i] - '0';
    }
    vector<vector<int>> dp(N + 1, vector<int>(2, 1e9));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][0] + A[i - 1], dp[i - 1][1] + 10 - A[i - 1]);
        dp[i][1] = min(dp[i - 1][0] + (A[i - 1] + 1), dp[i - 1][1] + 10 - (A[i - 1] + 1));
    }
    cout << dp[N][0] << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string L;
    cin >> L;
    int N = L.size();

    vector<vector<mint>> dp(N, vector<mint>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 2;
    for (int i = 1; i < N; ++i) {
        if (L[i] == '0') {
            dp[i][0] = dp[i - 1][0] * mint(3);
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][0] = dp[i - 1][0] * mint(3) + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1] * mint(2);
        }
    }
    cout << (dp[N - 1][0] + dp[N - 1][1]).val() << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, L;
    cin >> N >> L;
    vector<mint> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i - L >= 0) dp[i] = (dp[i - 1] + dp[i - L]);
        else dp[i] = dp[i - 1];
    }
    cout << dp[N].val() << endl;
}

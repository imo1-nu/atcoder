#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, P;
    cin >> N >> P;
    mint p1 = (mint)P / 100;
    mint p2 = 1 - p1;
    vector<mint> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = p1 * dp[i - 2] + p2 * dp[i - 1] + 1;
    }
    cout << dp[N].val() << endl;
}

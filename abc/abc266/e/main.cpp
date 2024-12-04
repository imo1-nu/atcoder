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
    vector<double> dp(N + 1);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 6; ++j) {
            dp[i] += max(double(j), dp[i - 1]) / 6;
        }
    }
    cout << fixed << setprecision(10) << dp[N] << endl;
}

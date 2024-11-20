#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> h(n), dp(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1] << endl;
}

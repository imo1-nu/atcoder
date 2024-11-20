#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        cin >> b[i];
    }

    vector<int> dp(n);
    dp[1] = a[1];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
    }
    cout << dp[n - 1] << endl;
}

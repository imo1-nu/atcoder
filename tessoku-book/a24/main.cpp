#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 0);
    vector<int> L(n + 1, 1e6);
    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(L.begin(), L.end(), a[i - 1]) - L.begin() - 1;
        dp[i] = k + 1;
        L[dp[i]] = min(L[dp[i]], a[i - 1]);
    }
    int i;
    for (i = 1; i <= n; i++) {
        if (L[i] == 1e6) break;
    }
    cout << i - 1 << endl;
    
}

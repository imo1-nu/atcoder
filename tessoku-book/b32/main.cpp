#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<bool> dp(n + 1);
    for (int i = a[0]; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= a[j] && !dp[i - a[j]]) dp[i] = true;
        }
    }
    
    if (dp[n]) cout << "First" << endl;
    else cout << "Second" << endl;
    
}

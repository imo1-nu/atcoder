#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    int ans = 1 << 30;
    
    for (int i = 0; i <= k; i++) {
        ans = min(ans, a[n - 1 - (k - i)] - a[i]);
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), cnt(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 1; i--) {
        cnt[a[i]] += cnt[i] + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << cnt[i];
        if (i < n) cout << ' ';
        else cout << endl;
    }
    
}

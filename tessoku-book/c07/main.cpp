#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> c(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + c[i];
    }
    
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < q; i++) {
        int ans = lower_bound(s.begin(), s.end(), x[i] + 1) - s.begin() - 1;
        cout << ans << endl;
    }
    
}

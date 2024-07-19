#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x, y, maxa = 1;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    
    vector<int> gr(maxa + 1, 0);
    for (int i = 0; i <= maxa; i++) {
        vector<bool> t(3, false);
        if (i - x >= 0) t[gr[i - x]] = true;
        if (i - y >= 0) t[gr[i - y]] = true;
        if (t[0] == false) gr[i] = 0;
        else if (t[1] == false) gr[i] = 1;
        else gr[i] = 2;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ gr[a[i]];
    }
    
    
    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
    
}

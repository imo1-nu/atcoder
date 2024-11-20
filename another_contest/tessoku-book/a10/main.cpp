#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, d;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> d;
    
    vector<pair<int, int>> p(n + 1);
    vector<int> ans(d);
    for (int i = 0; i < n; i++) {
        if (p[i].first < a[i]) p[i + 1].first = a[i];
        else p[i + 1].first = p[i].first;
    }
    p[n].second = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (p[i + 1].second < a[i - 1]) p[i].second = a[i - 1];
        else p[i].second = p[i + 1].second;
    }

    for (int i = 0; i < d; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << max(p[l].first, p[r + 2].second) << endl;
    }

    /*for (int i = 0; i < n; i++) {
        cout << p[i + 1].first;
        if (i < n - 1) cout << ' ';
        else cout << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i + 1].second;
        if (i < n - 1) cout << ' ';
        else cout << endl;
    }*/
    
    
}

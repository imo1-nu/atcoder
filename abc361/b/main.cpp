#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n = 12;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        if (a[i] > a[i + 3]) swap(a[i], a[i + 3]);
    }
    for (int i = 6; i < 9; i++) {
        if (a[i] > a[i + 3]) swap(a[i], a[i + 3]);
    }
    
    for (int i = 0; i < n; i++) {
        //cout << a[i] << endl;
    }
    
    bool ans = true;
    for (int i = 0; i < 3; i++) {
        if (a[i] >= a[i + 9] || a[i + 3] <= a[i + 6]) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

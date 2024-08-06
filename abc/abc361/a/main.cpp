#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << ' ';
        if (i == k - 1) cout << x << ' ';
    }
    cout << a[n - 1];
    if (k == n) cout << ' ' << x << endl;
    else cout << endl;
    
}

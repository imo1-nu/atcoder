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
    vector<int> t = a;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
    }
    
    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i < n - 1) cout << ' ';
        else cout << endl;
    }
    
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    bool r = false;
    for (int i = 0; i < q; i++) {
        int b, x, y;
        cin >> b;
        if (b == 1) {
            cin >> x >> y;
            if (r) a[n + 1 - x] = y;
            else a[x] = y;
        }
        else if (b == 2) r ^= true;
        else {
            cin >> x;
            if (r) cout << a[n + 1 - x] << endl;
            else cout << a[x] << endl;
        }
    }
    
}

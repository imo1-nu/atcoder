#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        if (i >= l && i <= r) cout << l + r - i;
        else cout << i;
        if (i < n) cout << ' ';
        else cout << endl;
    }
    
}

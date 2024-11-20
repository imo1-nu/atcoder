#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n;
    vector<int> a(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (s[r + 1] - s[l] > (r + 1 - l) / 2) cout << "win" << endl;
        else if (s[r + 1] - s[l] == (r + 1 - l) / 2 && (r + 1 - l) % 2 == 0) cout << "draw" << endl;
        else cout << "lose" << endl;
    }
    
}

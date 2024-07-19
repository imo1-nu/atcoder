#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll sx, sy, ty, tx;
    cin >> sx >> sy >> tx >> ty;
    if (sx > tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    if (sx % 2 == 1 && sy % 2 == 0 || sx % 2 == 0 && sy % 2 == 1) sx--;
    if (tx % 2 == 1 && ty % 2 == 0 || tx % 2 == 0 && ty % 2 == 1) tx--;
    sx += min(abs(sy - ty), tx - sx);
    ll ans = abs(sy - ty);
    ans += (tx - sx) / 2;
    cout << ans << endl;
}

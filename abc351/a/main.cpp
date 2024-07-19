#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    

    int ans = 0;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    for (int i = 0; i < 8; i++) {
        int a;
        cin >> a;
        ans -= a;
    }
    cout << ans + 1 << endl;
}

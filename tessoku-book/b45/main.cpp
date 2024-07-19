#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if (a + b + c == 0) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

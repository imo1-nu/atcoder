#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c;
    else
    return c * c * a;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if (a < myPow(c, b)) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

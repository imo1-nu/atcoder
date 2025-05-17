#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll myPow(ll a, ll b) {
    if (b == 1) return a;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b;
    cin >> a >> b;
    cout << myPow(a, b) << endl;
}

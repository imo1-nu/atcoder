#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c = 1000000007;

ll ans(ll a, ll b) {
    if (b == 1) return a;
    ll d = ans(a, b / 2);
    if (b % 2 == 0) return d * d % c;
    else return (d * d % c) * a % c;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b;
    cin >> a >> b;

    cout << ans(a, b) << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, A, X, Y;
    cin >> N >> A >> X >> Y;

    map<ll, double> mp;
    function<double(ll)> f = [&](ll n) -> double {
        if (n == 0) return 0;
        if (mp.count(n)) return mp[n];
        mp[n] = min(X + f(n / A), (6 * Y + f(n / 2) + f(n / 3) + f(n / 4) + f(n / 5) + f(n / 6)) / 5);
        return mp[n];
    };

    cout << fixed << setprecision(10) << f(N) << endl;
}

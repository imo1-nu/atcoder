#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i * i < N; i++) {
        if (N % i == 0) {
            ll div = N / i;
            if (N % (div - 1) != 0) ans += div - 1;
        }
    }

    cout << ans << endl;
}

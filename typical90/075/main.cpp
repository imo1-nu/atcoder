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
    ll cnt = 0ll;
    ll tmp = N;
    for (ll i = 2ll; i * i <= N; ++i) {
        while (tmp % i == 0) {
            tmp /= i;
            cnt++;
        }
    }
    if (tmp != 1) {
        cnt++;
    }

    ll i;
    for (i = 0; i <= 20; i++) {
        if ((1ll << i) >= cnt) {
            break;
        }
    }
    cout << i << endl;
}

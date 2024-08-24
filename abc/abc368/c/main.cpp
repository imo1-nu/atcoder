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
    vector<ll> H(N);
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll T = 0ll;
    for (ll i = 0; i < N; i++) {
        while (T % 3ll > 0ll && H[i] > 0ll) {
            if (T % 3ll == 1ll) H[i]--;
            else if (T % 3ll == 2ll) H[i] -= 3ll;
            T++;
        }
        if (H[i] > 0ll) {
            T += H[i] / 5ll * 3ll;
            H[i] %= 5ll;
            if (H[i] >= 3ll) T += 3ll;
            else T += H[i];
        }
    }
    cout << T << endl;
}

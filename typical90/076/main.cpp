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
    vector<ll> A(2ll * N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        A[N + i] = A[i];
    }

    ll sum = 0ll;
    for (ll i = 0; i < N; i++) {
        sum += A[i];
    }
    ll tgt = sum / 10ll;

    ll l = 0ll, r = 0ll;
    ll cnt = 0ll;
    bool ans = false;
    while (l < N) {
        if (r < l) r = l;
        while (r < 2ll * N && cnt < tgt) {
            cnt += A[r];
            r++;
        }
        if (cnt == tgt) {
            ans = true;
            break;
        }
        cnt -= A[l];
        l++;
    }

    if (sum % 10ll != 0) ans = false;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

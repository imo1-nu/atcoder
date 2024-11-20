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
    string S;
    cin >> S;

    vector<ll> A, B;
    for (ll i = 0; i < N; ++i) {
        if (S[i] == 'o') {
            A.push_back(i);
        } else {
            B.push_back(i);
        }
    }

    ll ans = 0;
    for (ll l = 0; l < N; l++) {
        if (S[l] == 'o') {
            ll r = lower_bound(B.begin(), B.end(), l) - B.begin();
            if (r == B.size()) continue;
            ans += N - B[r];
        }
        else {
            ll r = lower_bound(A.begin(), A.end(), l) - A.begin();
            if (r == A.size()) continue;
            ans += N - A[r];
        }
    }

    cout << ans << endl;
}
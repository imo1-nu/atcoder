#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    sort(A.begin(), A.end());

    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
        ll l = i;
        ll r = N;
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            if (A[mid].first <= A[i].second) l = mid;
            else r = mid;
        }
        cnt += l - i;
    }
    cout << cnt << endl;
}

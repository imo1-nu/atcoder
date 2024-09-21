#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    
    vector<vector<ll>> G1(N + 1), G2(N + 1);
    for (ll i = 0; i < 1ll << (N / 2); i++) {
        bitset<20> bs(i);
        ll sum = 0;
        ll cnt = 0;
        for (ll i = 0; i < N / 2; i++) {
            if (bs.test(i)) {
                sum += A[i];
                cnt++;
            }
        }
        G1[cnt].push_back(sum);
    }
    
    for (ll i = 0; i < 1ll << (N - N / 2); i++) {
        bitset<20> bs(i);
        ll sum = 0;
        ll cnt = 0;
        for (ll i = N / 2; i < N; i++) {
            if (bs.test(i - N / 2)) {
                sum += A[i];
                cnt++;
            }
        }
        G2[cnt].push_back(sum);
    }

    for (ll i = 0; i < N; i++) {
        sort(G2[i].begin(), G2[i].end());
    }
    
    ll ans = 0;
    for (ll i = 0; i <= K; i++) {
        for (ll j = 0; j < G1[i].size(); j++) {
            auto it = upper_bound(G2[K - i].begin(), G2[K - i].end(), P - G1[i][j]);
            ans += it - G2[K - i].begin();
        }
    }
    
    cout << ans << endl;
}

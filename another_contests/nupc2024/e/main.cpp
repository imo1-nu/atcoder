#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }
    ll ans = 0;
    if (M == 1) {
        for (auto [_, value] : mp) {
            ans += value * (value - 1) / 2 * (N - 2);
        }
    }
    else {
        ll max_num = 1;
        vector<ll> powM(60);
        powM[0] = 1;
        for (int i = 1; i < 60; i++) {
            if (powM[i - 1] > (ll)1e18 / M) {
                max_num = i;
                break;
            }
            powM[i] = powM[i - 1] * M;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < max_num; j++) {
                if (A[i] % powM[j] != 0) break;
                ll num = A[i] / powM[j];
                if (j == num) {
                    ans += mp[j] * (mp[j] - 1) / 2 * (N - mp[j]);
                }
            }
        }
    }
    

}

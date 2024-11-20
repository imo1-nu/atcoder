#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll K;
    cin >> K;
    vector<ll> vec;
    for (ll i = 1; i * i <= K; i++) {
        if (K % i != 0) continue;
        vec.push_back(i);
        if (i * i != K) vec.push_back(K / i);
    }
    
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for (ll i = 0; i < (ll)vec.size(); i++) {
        for (ll j = i; j < (ll)vec.size(); j++) {
            if (K / vec[i] < vec[j]) continue;
            if (K % (vec[i] * vec[j]) != 0ll) continue;
            if (vec[j] <= K / (vec[i] * vec[j])) ans++;
        }
    }
    cout << ans << endl;
}

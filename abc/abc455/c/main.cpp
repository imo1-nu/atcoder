#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    map<int, ll> mp;
    ll ans = 0;
    for (const auto& a : A) {
        mp[a] += a;
        ans += a;
    }
    priority_queue<ll> pq;
    for (auto& p : mp) pq.push(p.second);
    while (!pq.empty() && K--) {
        auto x = pq.top(); pq.pop();
        ans -= x;
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> work(n);
    for (ll i = 0; i < n; i++) {
        cin >> work[i].first >> work[i].second;
    }
    sort(work.begin(), work.end());
    priority_queue<ll> pq;
    ll cur = 0, ans = 0;
    for (ll i = 1; i <= d; i++) {
        while (i >= work[cur].first && cur < n) {
            pq.push(work[cur].second);
            cur++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

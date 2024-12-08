#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> X(N);
    vector<ll> C(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        X[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<ll> S(N);
    for (int i = 0; i < N; i++) {
        S[X[i]] += C[i];
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({S[i], i});
    }

    vector<bool> used(N);
    ll ans = 0;
    while (!pq.empty()) {
        auto [s, i] = pq.top();
        pq.pop();
        if (used[i]) continue;
        used[i] = true;
        ans += s;
        S[X[i]] -= C[i];
        pq.push({S[X[i]], X[i]});
    }
    cout << ans << endl;
}

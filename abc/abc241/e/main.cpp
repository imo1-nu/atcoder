#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll cur = 0;
    ll ans = 0;
    if (K < N) {
        for (ll i = 0; i < K; ++i) {
            ans += A[cur];
            cur = ans % N;
        }
        cout << ans << endl;
        return 0;
    }

    
    vector<ll> cost(N), dist(N);
    ll cycle_cost, cycle_length, cycle_start;
    while (1) {
        ans += A[cur];
        int next = ans % N;
        if (cost[next] != 0) {
            cycle_cost = cost[cur] + A[cur] - cost[next];
            cycle_length = dist[cur] - dist[next] + 1;
            cycle_start = next;
            break;
        }
        cost[next] = cost[cur] + A[cur];
        dist[next] = dist[cur] + 1;
        cur = next;
    }

    ans = cost[cycle_start];
    K -= dist[cycle_start];
    ans += cycle_cost * (K / cycle_length);
    K %= cycle_length;
    cur = cycle_start;
    while (K--) {
        ans += A[cur];
        cur = ans % N;
    }
    cout << ans << endl;
}

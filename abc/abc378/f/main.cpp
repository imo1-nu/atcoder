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
    vector<int> u(N - 1), v(N - 1), deg(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        deg[u[i]]++;
        deg[v[i]]++;
    }

    atcoder::dsu d(N);
    vector<int> cnt(N);
    for (int i = 0; i < N - 1; i++) {
        if (deg[u[i]] == 3 && deg[v[i]] == 3) {
            d.merge(u[i], v[i]);
        }
        else if (deg[u[i]] == 3 && deg[v[i]] == 2) {
            cnt[u[i]]++;
        }
        else if (deg[u[i]] == 2 && deg[v[i]] == 3) {
            cnt[v[i]]++;
        }
    }

    ll ans = 0;
    for (auto g : d.groups()) {
        ll c = 0;
        for (int v : g) {
            c += cnt[v];
        }
        ans += c * (c - 1) / 2;
    }

    cout << ans << endl;
}

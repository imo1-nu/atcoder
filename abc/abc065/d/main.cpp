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
    vector<pair<int, int>> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i].first >> Y[i].first;
        X[i].second = Y[i].second = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < N - 1; i++) {
        edges.emplace_back(X[i + 1].first - X[i].first, X[i].second, X[i + 1].second);
        edges.emplace_back(Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second);
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    atcoder::dsu d(N);
    for (const auto& [c, u, v] : edges) {
        if (d.same(u, v)) continue;
        d.merge(u, v);
        ans += c;
    }
    cout << ans << endl;
}

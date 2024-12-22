#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    function<int(int, int)> Pow = [&](int x, int y) -> ll {
        if (y == 0) return 1;
        ll z = Pow(x, y / 2);
        if (y % 2 == 0) return z * z % M;
        return z * z % M * x % M;
    };

    auto cost = [&](int i, int j) -> int {
        return (Pow(A[i], A[j]) + Pow(A[j], A[i])) % M;
    };

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edges.emplace_back(cost(i, j), i, j);
        }
    }
    sort(edges.rbegin(), edges.rend());

    atcoder::dsu d(N);
    ll ans = 0;
    for (auto [c, i, j] : edges) {
        if (d.same(i, j)) continue;
        ans += c;
        d.merge(i, j);
    }
    cout << ans << endl;
}

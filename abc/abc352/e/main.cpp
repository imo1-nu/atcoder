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
    vector<tuple<int, int, int>> edges;
    vector<vector<int>> A(M);
    for (int i = 0; i < M; i++) {
        int K, C;
        cin >> K >> C;
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
            edges.emplace_back(C, A[i][0], a);
        }
    }
    sort(edges.begin(), edges.end());

    atcoder::dsu d(N);
    ll ans = 0;
    for (auto [c, a, b] : edges) {
        if (d.same(a, b)) continue;
        d.merge(a, b);
        ans += c;
    }

    if (d.groups().size() == 1) cout << ans << endl;
    else cout << -1 << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    atcoder::dsu dsu(N);
    vector<tuple<int, int, int>> unused;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (!dsu.same(a, b)) dsu.merge(a, b);
        else unused.emplace_back(i, a, b);
    }

    set<int> leaders;
    for (int i = 0; i < N; i++) {
        leaders.insert(dsu.leader(i));
    }
    int K = leaders.size() - 1;
    cout << K << endl;
    for (int i = 0; i < K; i++) {
        auto [j, a, b] = unused[i];
        int r1 = dsu.leader(a);
        int r2;
        for (auto l : leaders) {
            if (l != r1) {
                r2 = l;
                break;
            }
        }
        cout << j + 1 << ' ' << a + 1 << ' ' << r2 + 1 << endl;
        dsu.merge(a, r2);
        if (dsu.leader(r1) == r1) leaders.erase(r2);
        else leaders.erase(r1);
    }
}

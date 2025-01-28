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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    atcoder::scc_graph g(N);
    for (int i = 0; i < N; i++) {
        g.add_edge(i, A[i]);
    }
    auto scc = g.scc();

    int ans = 0;
    for (auto &v : scc) {
        if (v.size() > 1 || v[0] == A[v[0]]) {
            ans += v.size();
        }
    }
    cout << ans << endl;
}

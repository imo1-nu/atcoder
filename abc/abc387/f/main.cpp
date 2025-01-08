#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    atcoder::scc_graph scc(N);
    for (int i = 0; i < M; i++) {
        scc.add_edge(i, A[i]);
    }
    auto sccs = scc.scc();
    int scc_num = sccs.size();
    vector<int> group(N);
    for (int i = 0; i < scc_num; i++) {
        for (int j : sccs[i]) {
            group[j] = i;
        }
    }
}

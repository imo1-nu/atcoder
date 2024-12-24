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
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    atcoder::dsu d(N);
    for (int i = 0; i < N; ++i) {
        for (int j : G[i]) {
            if (i < j) {
                d.merge(i, j);
            }
        }
    }

    bool ans = true;
    vector<int> cnt(M + 1);
    for (int i = 0; i < N; ++i) {
        cnt[G[i].size()]++;
        if (d.leader(i) != d.leader(0)) {
            ans = false;
            break;
        }
    }
    if (cnt[1] != 2 || cnt[2] != N - 2) {
        ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

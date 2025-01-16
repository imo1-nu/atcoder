#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using P = pair<ll, int>;
const long long INF = 1LL << 60;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> L(M), D(M), K(M), C(M), A(M), B(M);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> D[i] >> K[i] >> C[i] >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[B[i]].push_back(i);
    }

    vector<ll> ans(N, -INF);
    ans[N - 1] = INF;
    priority_queue<P> pq;
    pq.emplace(ans[N - 1], N - 1);
    while (!pq.empty()) {
        auto [f, b] = pq.top();
        pq.pop();
        if (ans[b] > f) continue;
        for (auto id : G[b]) {
            ll l = L[id], d = D[id], k = K[id], c = C[id], a = A[id];
            ll tmp = (f - l - c);
            if (tmp < 0) continue;
            tmp = min(tmp / d, k - 1);
            ll nf = l + tmp * d;
            if (ans[a] < nf) {
                ans[a] = nf;
                pq.emplace(nf, a);
            }
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (ans[i] == -INF) cout << "Unreachable" << endl;
        else cout << ans[i] << endl;
    }
}

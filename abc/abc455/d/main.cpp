#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> C(Q), P(Q);
    for (int i = 0; i < Q; i++) {
        cin >> C[i] >> P[i];
        C[i]--; P[i]--;
    }
    vector<pair<int, int>> nodes(2 * N);
    for (int i = 0; i < N; i++) {
        auto& node = nodes[i];
        node.first = -1;
        node.second = i + N;
    }
    for (int i = N; i < 2 * N; i++) {
        auto& node = nodes[i];
        node.first = i - N;
        node.second = -1;
    }

    for (int i = 0; i < Q; i++) {
        auto& c = nodes[C[i] + N];
        auto& p = nodes[P[i] + N];
        nodes[c.first].second = -1;
        c.first = P[i] + N;
        p.second = C[i] + N;
    }
    for (int i = 0; i < N; i++) {
        auto node = nodes[i];
        int cnt = 0;
        while (node.second != -1) {
            cnt++;
            node = nodes[node.second];
        }
        cout << cnt << ' ';
    }
    cout << endl;
}

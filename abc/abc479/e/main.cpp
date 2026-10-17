#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int> sub(N, 1);
    vector<bool> visited(N);
    vector<int> pos(N);
    int idx = 0;
    function<int(int)> dfs = [&](int u) {
        visited[u] = true;
        pos[u] = idx;
        idx++;
        for (auto v : G[u]) {
            if (visited[v]) continue;
            sub[u] += dfs(v);
        }
        return sub[u];
    };
    dfs(0);

    vector<ll> diff(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int cnt = 0;
        int l, r;
        if (sub[A[i]] > sub[B[i]]) {
            cnt = sub[B[i]];
            l = pos[B[i]];
            r = pos[B[i]] + sub[B[i]];
        }
        else {
            cnt = sub[A[i]];
            l = pos[A[i]];
            r = pos[A[i]] + sub[A[i]];
        }

        if (2 * cnt > N) {
            diff[l] += i + 1;
            diff[r] -= i + 1;
        }
        else {
            diff[0] += i + 1;
            diff[l] -= i + 1;
            diff[r] += i + 1;
            diff[N] -= i + 1;
        }
    }

    vector<ll> sum(N + 1);
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + diff[i - 1];

    for (int i = 0; i < N; i++) cout << sum[pos[i] + 1] << ' ';
    cout << endl;
}

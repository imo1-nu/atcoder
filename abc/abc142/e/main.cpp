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
    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        for (int j = 0; j < B[i]; j++) {
            int c;
            cin >> c;
            C[i] |= 1 << (c - 1);
        }
    }

    vector<int> dist(1 << N, 1e9);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        if (dist[p.second] < p.first) {
            continue;
        }
        for (int i = 0; i < M; i++) {
            int T = p.second | C[i];
            if (dist[T] > dist[p.second] + A[i]) {
                dist[T] = dist[p.second] + A[i];
                que.push({dist[T], T});
            }
        }
    }

    if (dist[(1 << N) - 1] == 1e9) {
        cout << -1 << endl;
    }
    else {
        cout << dist[(1 << N) - 1] << endl;
    }
}

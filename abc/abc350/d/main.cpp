#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> C(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    vector<bool> seen(N, false);
    queue<int> bfs;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (seen[i] == true) continue;
        bfs.push(i);
        int node_num = 0;
        int edge_num = 0;
        while (!bfs.empty()) {
            int j = bfs.front();
            bfs.pop();
            node_num++;
            while (!C[i].empty()) {
                int c = C[i][0];
            }
        }
        seen[i] = true;
    }
}

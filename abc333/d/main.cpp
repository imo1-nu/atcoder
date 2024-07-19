#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, u, v;
    cin >> N;
    vector<vector<bool>> edge(N, vector<bool>(N, false));
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
        cnt[u]++;
        cnt[v]++;
    }
}

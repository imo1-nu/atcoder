#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": {";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j];
            if (j < g[i].size() - 1) cout << ", ";
        }
        cout << '}' << endl;
    }
    
    
}

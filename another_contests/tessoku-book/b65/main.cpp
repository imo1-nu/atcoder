#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> G(100009);
vector<bool> checked(100009);
vector<int> ans(100009);

int dfs(int pos) {
    checked[pos] = true;
    for (auto i : G[pos]) if (!checked[i]) ans[pos] = max(ans[pos], dfs(i) + 1);
    return ans[pos];
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;
    t--;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    dfs(t);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N, M;

void dfs(vector<int> a, vector<vector<int>> &ans)
{
    int sz = a.size();
    if (sz == N) {
        ans.push_back(a);
        return;
    }
    int start = 1;
    if (sz > 0) start = a[sz-1] + 10;
    for (int i = start; i <= M - 10 * (N - sz - 1); i++) {
        vector<int> b = a;
        b.push_back(i);
        dfs(b, ans);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    vector<vector<int>> ans;
    dfs({}, ans);

    cout << ans.size() << endl;
    for (auto &a : ans) {
        for (int i = 0; i < N; i++) {
            cout << a[i];
            if (i < N - 1) cout << " ";
        }
        cout << endl;
    }
}

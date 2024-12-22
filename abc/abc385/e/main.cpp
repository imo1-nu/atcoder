#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int ans = N;
    for (int i = 0; i < N; ++i) {
        vector<int> div(G[i].size());
        for (int j = 0; j < (int)G[i].size(); ++j) {
            int v = G[i][j];
            div[j] = (int)G[v].size();
        }
        sort(div.rbegin(), div.rend());
        for (int x = 1; x <= (int)div.size(); ++x) {
            int y = div[x - 1] - 1;
            ans = min(ans, N - 1 - x - x * y);
        }
    }
    cout << ans << endl;
}

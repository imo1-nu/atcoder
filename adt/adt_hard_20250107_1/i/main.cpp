#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> C;
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        C.emplace_back(r, c);
    }
    C.push_back({0, 0});
    sort(C.begin(), C.end());

    vector<int> dp(N + 1, 1e9), id(N + 1, -1), pre(N + 1, -1);
    for (int i = 0; i < N + 1; i++) {
        int idx = upper_bound(dp.begin(), dp.end(), C[i].second) - dp.begin();
        dp[idx] = C[i].second;
        id[idx] = i;
        if (idx > 0) pre[i] = id[idx - 1]; 
    }
    int len = N;
    while (id[len] == -1) len--;
    vector<pair<int, int>> path = {{H - 1, W - 1}};
    for (int i = id[len]; i != -1; i = pre[i]) {
        path.push_back(C[i]);
    }
    reverse(path.begin(), path.end());
    string S;
    for (int i = 0; i < (int)path.size() - 1; i++) {
        int r = path[i + 1].first - path[i].first;
        int c = path[i + 1].second - path[i].second;
        S += string(r, 'D') + string(c, 'R');
    }
    cout << len << endl << S << endl;
}

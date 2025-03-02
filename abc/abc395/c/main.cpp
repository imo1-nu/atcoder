#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> pos(1000001);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pos[a].push_back(i);
    }
    int ans = 1e9;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 0; j < (int)pos[i].size() - 1; j++) {
            ans = min(ans, pos[i][j + 1] - pos[i][j] + 1);
        }
    }
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}
